/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:06:08 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/06 03:20:16 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_philo(t_table *table, t_philo **philo)
{
	int i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_head);
	if (philo == NULL)
		return (1);
	i = -1;
	while (++i < table->philo_head)
	{
		philo[i]->philo_num = i + 1;
		philo[i]->left_fork = &table->all_fork[i];
		philo[i]->right_fork = &table->all_fork[(i + 1) % table->philo_head];
		philo[i]->eat_count = 0;
		philo[i]->table = table;
	}
	return (0);
}