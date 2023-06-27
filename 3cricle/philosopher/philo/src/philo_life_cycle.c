/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 22:29:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	waiting(t_table *table, int time)
{
	long	start;
	long	now;

	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start >= time)
			return ;
		(void ) table;
		pthread_mutex_lock(&table->m_is_dead);
		if (table->is_dead)
		{
			pthread_mutex_unlock(&table->m_is_dead);
			break ;
		}
		pthread_mutex_unlock(&table->m_is_dead);
		usleep(100);
	}
}

int	go_to_eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&(table->fork[philo->left_fork]));
	if (print_log(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(&(table->fork[philo->right_fork]));
	if (print_log(philo, "has taken a fork"))
		return (1);
	if (print_log(philo, "is eating"))
		return (1);
	waiting(table, table->time_to_eat);
	pthread_mutex_lock(&table->m_last_eaten[philo->philo_num - 1]);
	philo->last_eaten = get_time();
	if (philo->last_eaten == -1)
		return (1);
	pthread_mutex_unlock(&table->m_last_eaten[philo->philo_num - 1]);
	philo->eat_count++;
	pthread_mutex_unlock(&(table->fork[philo->right_fork]));
	pthread_mutex_unlock(&(table->fork[philo->left_fork]));
	return (0);
}

int	go_to_sleep(t_philo *philo, t_table *table)
{
	if (print_log(philo, "is sleeping"))
		return (1);
	waiting(table, table->time_to_sleep);
	return (0);
}

int	check_end(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->m_is_dead);
	if (table->is_dead)
	{
		pthread_mutex_unlock(&table->m_is_dead);
		return (1);
	}
	pthread_mutex_unlock(&table->m_is_dead);
	if (table->eat_count != 0 && philo->eat_count == table->eat_count)
	{
		pthread_mutex_lock(&table->m_is_full);
		table->is_full += 1;
		pthread_mutex_unlock(&table->m_is_full);
		return (1);
	}
	return (0);
}

void	*philo_life_cycle(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	if (philo->philo_num % 2 == 0)
		usleep(100);
	while (1)
	{
		if (go_to_eat(philo, table))
			break ;
		if (go_to_sleep(philo, table))
			break ;
		print_log(philo, "is thinking");
		if (check_end(philo, table))
			break ;
	}
	return (0);
}
