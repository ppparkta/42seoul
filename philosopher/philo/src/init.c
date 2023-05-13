/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:53:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 13:08:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_table *table, t_philo *philo)
{
	int	i;

	memset(philo, 0, sizeof(t_philo));
	i = -1;
	while (++i < table->philo_head)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].philo_num = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % table->philo_head;
		philo[i].table = table;
	}
	return (0);
}

int	init_args(t_table *table, int argc, char **argv)
{
	int	i;
	int	num;

	memset(table, 0, sizeof(t_table));
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (!num)
			return (1);
		if (i == 1)
			table->philo_head = num;
		else if (i == 2)
			table->time_to_die = num;
		else if (i == 3)
			table->time_to_eat = num;
		else if (i == 4)
			table->time_to_sleep = num;
		else if (i == 5)
			table->eat_count = num;
		i++;
	}
	return (0);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (init_args(table, argc, argv))
		return (print_error_message("arg error"));
	table->start_time = get_time();
	if (init_mutex(table))
		return (1);
	return (0);
}

int	init(t_philo **philo, t_table *table, int argc, char **argv)
{
	if (init_table(table, argc, argv))
		return (1);
	*philo = malloc(sizeof(t_philo) * table->philo_head);
	if (!*philo)
		return (mutex_error(table, "malloc error"));
	init_philo(table, *philo);
	return (0);
}
