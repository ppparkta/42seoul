/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:53:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/07 00:44:45 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_argv(int argc, char **argv)
{
	int i;

	i = -1;
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

	table->all_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->philo_head);
	if (table->all_fork == 0)
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
	if (argc == 6)
		table->eat_count = ft_atoi(argv[5]);
	else
		table->eat_count = 0;
	table->is_dead = 0;
	if (create_fork(table))
		return (1);
	return (0);
}
