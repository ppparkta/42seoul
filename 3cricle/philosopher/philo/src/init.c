/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:53:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 21:32:22 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_args(t_table *table, int argc, char **argv)
{
	int	i;
	int	num;

	memset(table, 0, sizeof(t_table));
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i], table);
		if (num < 1 || table->error == 1)
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

int	init_info(t_table *table, int argc, char **argv)
{
	if (init_args(table, argc, argv))
		return (print_error_message("argument error"));
	table->start_time = get_time();
	if (init_mutex(table))
		return (1);
	return (0);
}

void	init_philo(t_philo *philo, t_table *table)
{
	int	i;

	memset(philo, 0, sizeof(t_philo));
	i = 0;
	while (i < table->philo_head)
	{
		memset(&(philo[i]), 0, sizeof(t_philo));
		philo[i].philo_num = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % table->philo_head ;
		philo[i].table = table;
		i++;
	}
}

int	init(t_philo **philo, t_table *table, int argc, char **argv)
{
	if (init_info(table, argc, argv))
		return (1);
	*philo = malloc(sizeof(t_philo) * table->philo_head);
	if (!*philo)
		return (mutex_error(table, "malloc error"));
	init_philo(*philo, table);
	return (0);
}
