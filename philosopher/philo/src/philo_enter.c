/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_enter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 15:29:38 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void philo_only_one(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%d %d has taken a fork\n", 0, \
		philo->philo_num);
}

int	check_dead(t_table *table)
{
	int	swc;

	pthread_mutex_lock(&table->m_is_dead);
	swc = table->is_dead;
	pthread_mutex_unlock(&table->m_is_dead);
	return (swc);
}

void	*philo_life_cycle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->philo_head == 1)
	{
		philo_only_one(philo);
		return (0);
	}
	if (philo->philo_num % 2 == 0)
		usleep(philo->table->time_to_eat * 500);
	while (philo->is_full == 0 && check_dead(philo->table) == 0)
	{
		pick_up_fork(philo);
		go_to_eat(philo);
		put_down_fork(philo);
		go_to_sleep(philo);
		go_to_think(philo);
	}
	return (0);
}

int	philo_enter(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->m_is_dead);
	while (++i < table->philo_head)
		pthread_create(&philo[i].thread, NULL, philo_life_cycle, &philo[i]);
	set_time(table, philo);
	pthread_mutex_unlock(&table->m_is_dead);
	return (1);
}