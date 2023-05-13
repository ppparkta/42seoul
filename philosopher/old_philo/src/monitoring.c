/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:28:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 06:33:11 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_full(t_table *table, t_philo *philo)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < table->philo_head)
	{
		pthread_mutex_lock(&table->m_is_full);
			cnt += philo[i].is_full;
		pthread_mutex_unlock(&table->m_is_full);
	}
	if (cnt == table->philo_head)
		return (1);
	return (0);
}

int	check_starvation(t_philo *philo)
{
	long long	hungry_time;
	t_table		*table;

	table = philo->table;
	pthread_mutex_lock(&table->m_time_to_last_eaten[philo->philo_num - 1]);
	hungry_time = get_time_table(philo->time_to_last_eaten);
	pthread_mutex_unlock(&table->m_time_to_last_eaten[philo->philo_num - 1]);
	if (hungry_time > philo->table->time_to_die)
	{
		print_msg(philo, " died\n");
		pthread_mutex_lock(&philo->table->m_is_dead);
		philo->table->is_dead = 1;
		pthread_mutex_unlock(&philo->table->m_is_dead);
		return (1);
	}
	return (0);
}

void	end_simulation(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->philo_head)
		pthread_detach(philo[i].thread);
	i = -1;
	while (++i < table->philo_head)
	{
		pthread_mutex_destroy(&table->m_time_to_last_eaten[i]);
		pthread_mutex_destroy(&table->all_fork[i]);
	}
	pthread_mutex_destroy(&table->m_is_full);
	pthread_mutex_destroy(&table->m_is_dead);
	pthread_mutex_destroy(&table->print);
}

void	monitoring(t_table *table, t_philo *philo)
{
	int	i;
	int	flag;

	while (1)
	{
		i = -1;
		flag = 0;
		while ((++i < table->philo_head) && (check_dead(table) == 0))
		{
			if (check_starvation(&philo[i]))
			{
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
		if (is_full(table, philo))
			break ;
		usleep(100);
	}
}
