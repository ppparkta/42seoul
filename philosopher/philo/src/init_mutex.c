/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 08:44:58 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 18:49:59 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_fork(t_table *table)
{
	int	i;

	table->all_fork = malloc(sizeof(pthread_mutex_t) * table->philo_head);
	if (!table->all_fork)
		return (print_error_message("malloc error"));
	i = -1;
	while (++i < table->philo_head)
	{
		if (pthread_mutex_init(&(table->all_fork[i]), NULL) == -1)
		{
			pthread_mutex_destroy(&(table->print));
			pthread_mutex_destroy(&(table->m_is_dead));
			pthread_mutex_destroy(&(table->m_is_full));
			table->philo_head = i;
			i = -1;
			while (++i < table->philo_head)
				pthread_mutex_destroy(&(table->all_fork[i]));
			free(table->all_fork);
			return (print_error_message("mutex init error"));
		}
		i++;
	}
	return (0);
}

int	init_last_eaten(t_table *table)
{
	int	i;

	table->m_time_to_last_eaten = \
	malloc(sizeof(pthread_mutex_t) * table->philo_head);
	if (!table->m_time_to_last_eaten)
		return (print_error_message("malloc error"));
	i = 0;
	while (i < table->philo_head)
	{
		if (pthread_mutex_init(&(table->m_time_to_last_eaten[i]), NULL) == -1)
		{
			pthread_mutex_destroy(&(table->print));
			pthread_mutex_destroy(&(table->m_is_full));
			pthread_mutex_destroy(&(table->m_is_dead));
			table->philo_head = i;
			i = -1;
			while (++i < table->philo_head)
				pthread_mutex_destroy(&(table->m_time_to_last_eaten[i]));
			free(table->m_time_to_last_eaten);
			return (print_error_message("mutex init error"));
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&(table->print), NULL) == -1)
		return (print_error_message("mutex init error"));
	if (pthread_mutex_init(&(table->m_is_full), NULL) == -1)
	{
		pthread_mutex_destroy(&(table->print));
		return (print_error_message("mutex init error"));
	}
	if (pthread_mutex_init(&(table->m_is_dead), NULL) == -1)
	{
		pthread_mutex_destroy(&(table->print));
		pthread_mutex_destroy(&(table->m_is_full));
		return (print_error_message("mutex init error"));
	}
	if (init_fork(table) || init_last_eaten(table))
		return (1);
	return (0);
}
