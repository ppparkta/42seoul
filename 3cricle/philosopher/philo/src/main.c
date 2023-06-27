/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 22:34:36 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_thread(t_philo *philo)
{
	int		i;
	long	now;

	i = 0;
	now = get_time();
	while (i < philo->table->philo_head)
	{
		philo[i].last_eaten = now;
		if (pthread_create(&philo[i].thread, NULL, philo_life_cycle, \
		&(philo[i])))
			return (error(philo, "philo thread create error"));
		i++;
	}
	return (0);
}

int	monitor_thread(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, monitoring, philo))
		return (error(philo, "monitor thread create error"));
	pthread_join(monitor, NULL);
	return (0);
}

int	philo_join(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->table->philo_head == 1)
		pthread_detach(philo[i].thread);
	else
	{
		while (i < philo->table->philo_head)
		{
			printf("%d join!!!\n", philo->philo_num);
			if (pthread_join(philo[i].thread, NULL) != 0)
				return (error(philo, "thread join error"));
			i++;
		}
	}	
	return (0);
}

int	philo_enter(t_philo *philo)
{
	if (philo_thread(philo))
		return (1);
	if (monitor_thread(philo))
		return (1);
	if (philo_join(philo))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
		return (print_error_message("argument error"));
	if (init(&philo, &table, argc, argv))
		return (1);
	if (philo_enter(philo))
		return (1);
	destroy_mutex(&table);
	free(philo->table->fork);
	free(philo->table->m_last_eaten);
	free(philo);
}
