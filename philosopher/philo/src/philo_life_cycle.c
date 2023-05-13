/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 19:19:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_only_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->all_fork[philo->left_fork]);
	printf("%d %d has taken a fork\n", 0, \
		philo->philo_num);
}

int	go_to_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&(table->all_fork[philo->left_fork]));
	if (print_act(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(&(table->all_fork[philo->right_fork]));
	if (print_act(philo, "has taken a fork"))
		return (1);
	if (print_act(philo, "is eating"))
		return (1);
	pass_time(philo, table->time_to_eat);
	pthread_mutex_lock(&(table->m_time_to_last_eaten[philo->philo_num - 1]));
	philo->time_to_last_eaten = get_time();
	pthread_mutex_unlock(&(table->m_time_to_last_eaten[philo->philo_num - 1]));
	philo->eat_count++;
	pthread_mutex_unlock(&(table->all_fork[philo->left_fork]));
	pthread_mutex_unlock(&(table->all_fork[philo->right_fork]));
	return (0);
}

int	go_to_sleep(t_philo *philo)
{
	if (print_act(philo, "is sleeping"))
		return (1);
	pass_time(philo, philo->table->time_to_sleep);
	return (0);
}

int	philo_life(t_philo *philo)
{
	if (go_to_eat(philo))
		return (1);
	if (go_to_sleep(philo))
		return (1);
	if (print_act(philo, "is thinking"))
		return (1);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&philo->table->m_is_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	return (0);
}

void	*philo_life_cycle(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	if (table->philo_head == 1)
	{
		philo_only_one(philo);
		return (0);
	}
	if (philo->philo_num % 2 == 0)
		usleep(100);
	while (1)
	{
		if (philo_life(philo))
			break ;
		if (table->eat_count != 0 && philo->eat_count == table->eat_count)
		{
			pthread_mutex_lock(&table->m_is_full);
			table->is_full += 1;
			pthread_mutex_unlock(&table->m_is_full);
			break ;
		}
	}
	return (0);
}
