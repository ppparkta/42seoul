/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_enter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 17:53:16 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_only_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->all_fork[philo->left_fork]);
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

int	cycle(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->all_fork[philo->left_fork]);
	if (print_msg(philo, " has taken a fork\n"))
		return (1);
	pthread_mutex_lock(&philo->table->all_fork[philo->right_fork]);
	if (print_msg(philo, " has taken a fork\n"))
		return (1);
	if (print_msg(philo, " is eating\n"))
		return (1);
	pass_time(philo->table->time_to_eat, philo);
	pthread_mutex_lock(&philo->table->m_time_to_last_eaten[philo->philo_num - 1]);
	philo->time_to_last_eaten = get_time();
	pthread_mutex_unlock(&philo->table->m_time_to_last_eaten[philo->philo_num - 1]);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->table->all_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->all_fork[philo->right_fork]);
	if (print_msg(philo, " is sleeping\n"))
		return (1);
	pass_time(philo->table->time_to_sleep, philo);
	if (print_msg(philo, " is thinking\n"))
		return (1);
	if (check_dead(philo->table))
		return (1);
	return (0);
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
		usleep(100);
	// while (1)
	// {
	// 	if (cycle(philo))
	// 		break ;
	// 	if (philo->table->eat_count && \
	// 	(philo->eat_count == philo->table->eat_count))
	// 		break ;
	// }
	while (philo->is_full == 0 && check_dead(philo->table) == 0)
	{
		if (check_dead(philo->table))
			break ;
		go_to_eat(philo);
		if (check_dead(philo->table))
			break ;
		go_to_sleep(philo);
		if (check_dead(philo->table))
			break ;
		print_msg(philo, " is thinking\n");
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
