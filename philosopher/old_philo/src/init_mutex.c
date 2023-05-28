/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:33:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 21:36:29 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_fork_mutex(t_table *table)
{
	int	i;

	table->fork = malloc(sizeof(pthread_mutex_t) * table->philo_head);
	if (!table->fork)
		return (print_error_message("malloc error"));
	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_mutex_init(&(table->fork[i]), NULL))
		{
			pthread_mutex_destroy(&(table->print));
			pthread_mutex_destroy(&(table->end_m));
			pthread_mutex_destroy(&(table->die_m));
			table->philo_num = i;
			i = -1;
			while (++i < table->philo_num)
				pthread_mutex_destroy(&(table->fork[i]));
			free(table->fork);
			return (print_error_message("mutex init error"));
		}
		i++;
	}
	return (0);
}

int	init_last_eat_mutex(t_info *table)
{
	int	i;

	table->last_eat_m = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (!table->last_eat_m)
		return (print_error_message("malloc error"));
	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_mutex_init(&(table->last_eat_m[i]), NULL))
		{
			pthread_mutex_destroy(&(table->print));
			pthread_mutex_destroy(&(table->end_m));
			pthread_mutex_destroy(&(table->die_m));
			table->philo_num = i;
			i = -1;
			while (++i < table->philo_num)
				pthread_mutex_destroy(&(table->last_eat_m[i]));
			free(table->last_eat_m);
			return (print_error_message("mutex init error"));
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&(table->print), NULL))
		return (print_error_message("mutex init error"));
	if (pthread_mutex_init(&(table->m_is_dead), NULL))
	{
		pthread_mutex_destroy(&(table->print));
		return (print_error_message("mutex init error"));
	}
	if (pthread_mutex_init(&(table->m_is_full), NULL))
	{
		pthread_mutex_destroy(&(table->print));
		pthread_mutex_destroy(&(table->m_is_dead));
		return (print_error_message("mutex init error"));
	}
	if (init_fork_mutex(table) || init_last_eat_mutex(table))
		return (1);
	return (0);
}
