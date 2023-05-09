/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:28:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 22:07:36 by sooyang          ###   ########.fr       */
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
		pthread_mutex_lock(&philo[i].m_is_full);
			cnt += philo[i].is_full;
		pthread_mutex_unlock(&philo[i].m_is_full);
	}
	if (cnt == table->philo_head)
		return (1);
	return (0);
}

int	check_starvation(t_philo *philo)
{
	long long	hungry_time;

	pthread_mutex_lock(&philo->m_time_to_last_eaten);
	hungry_time = get_time_table(philo->time_to_last_eaten);
	pthread_mutex_unlock(&philo->m_time_to_last_eaten);
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
	{
		pthread_join(philo[i].thread, NULL);
	}
}

void	monitoring(t_table *table, t_philo *philo)
{
	int	i;

	while (check_dead(table) == 0 && is_full(table, philo) == 0)
	{
		i = -1;
		while ((++i < table->philo_head) && (check_dead(table) == 0))
		{
			if (check_starvation(&philo[i]))
				break ;
		}
		usleep(100);
	}
	end_simulation(table, philo);
	free(table->all_fork);
	free(philo);
}
