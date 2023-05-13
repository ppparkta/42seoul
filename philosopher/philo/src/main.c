/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 19:28:51 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	join_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->philo_head)
	{
		if (pthread_join((philo[i]).thread, NULL) != 0)
			return (error_all(philo, "join error"));
		i++;
	}	
	return (0);
}

int	create_monitor(t_philo *philo)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, monitoring, philo))
		return (error_all(philo, "thread create error"));
	if (pthread_join(monitor_thread, NULL))
		return (error_all(philo, "join error"));
	return (0);
}

int	create_philo(t_philo *philo)
{
	int			i;
	long long	now;

	i = -1;
	now = get_time();
	while (++i < philo->table->philo_head)
	{
		philo[i].time_to_last_eaten = now;
		if (pthread_create(&philo[i].thread, NULL, \
		philo_life_cycle, &(philo[i])))
			return (error_all(philo, "thread create error"));
	}
	return (0);
}

int	enter_philo(t_philo *philo)
{
	if (create_philo(philo))
		return (1);
	if (create_monitor(philo))
		return (1);
	if (join_philo(philo))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_table	table;

	if (argc < 5 || argc > 6)
		return (print_error_message("arg error"));
	if (init(&philo, &table, argc, argv))
		return (1);
	if (enter_philo(philo))
		return (1);
	destroy_mutex(&table);
	free(philo->table->all_fork);
	free(philo->table->m_time_to_last_eaten);
	free(philo);
	return (0);
}
