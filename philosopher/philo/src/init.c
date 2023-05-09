/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:53:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 21:44:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_table *table, t_philo **philo)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_head);
	if (!philo)
		return (1);
	i = -1;
	while (++i < table->philo_head)
	{
		(*philo)[i].philo_num = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % table->philo_head;
		(*philo)[i].eat_count = 0;
		(*philo)[i].is_full = 0;
		(*philo)[i].table = table;
		pthread_mutex_init(&(*philo)[i].m_is_full, NULL);
		pthread_mutex_init(&(*philo)[i].m_time_to_last_eaten, NULL);
	}
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
			return (1);
	}
	return (0);
}

int	create_fork(t_table *table)
{
	int	i;

	table->all_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)\
		* table->philo_head);
	if (table->all_fork == NULL)
		return (1);
	i = -1;
	while (++i < table->philo_head)
	{
		if (pthread_mutex_init(&table->all_fork[i], NULL))
			return (1);
	}
	return (0);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (check_argv(argc, argv))
		return (1);
	table->philo_head = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->eat_count = ft_atoi(argv[5]);
	else
		table->eat_count = 0;
	table->is_dead = 0;
	pthread_mutex_init(&table->m_is_dead, NULL);
	pthread_mutex_init(&table->print, NULL);
	if (create_fork(table))
		return (1);
	return (0);
}
