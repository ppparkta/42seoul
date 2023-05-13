/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 04:57:07 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 05:16:32 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_fork(t_table *table)
{
	int	i;

	table->all_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->philo_head);
	if (table->all_fork == NULL)
		return (1);
	i = -1;
	while (++i < table->philo_head)
	{
		if (pthread_mutex_init(&table->all_fork[i], NULL) == -1)
		{
			pthread_mutex_destroy(&(table->print));
			pthread_mutex_destroy(&(table->m_is_dead));
			pthread_mutex_destroy(&(table->m_is_full));
			table->philo_head = i;
			i = -1;
			while (++i < table->philo_head)
				pthread_mutex_destroy(&(table->all_fork[i]));
			free(table->all_fork);
			return (1);
		}
	}
	return (0);
}

int	create_last_eaten(t_table *table)
{
	int	i;

	table->m_time_to_last_eaten = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->philo_head);
	if (table->m_time_to_last_eaten == NULL)
		return (1);
	i = -1;
	while (++i < table->philo_head)
	{
		if (pthread_mutex_init(&table->m_time_to_last_eaten[i], NULL) == -1)
		{
			pthread_mutex_destroy(&table->print);
			pthread_mutex_destroy(&table->m_is_full);
			pthread_mutex_destroy(&table->m_is_dead);
			table->philo_head = i;
			i = -1;
			while (++i < table->philo_head)
				pthread_mutex_destroy(&(table->m_time_to_last_eaten[i]));
			free(table->m_time_to_last_eaten);
			return (1);
		}
	}
	return (0);
}

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->m_is_dead, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&table->print, NULL) == -1)
	{
		pthread_mutex_destroy(&table->m_is_dead);
		return (1);
	}
	if (pthread_mutex_init(&table->m_is_full, NULL) == -1)
	{
		pthread_mutex_destroy(&table->m_is_dead);
		pthread_mutex_destroy(&table->print);
		return (1);
	}
	if (create_fork(table) || create_last_eaten(table))
		return (1);
	return (0);
}
