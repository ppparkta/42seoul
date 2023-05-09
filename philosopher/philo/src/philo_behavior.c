/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:44:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 16:11:32 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	go_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		printf("%lld %d is eating\n", get_time_table(philo->table->start_time), \
		philo->philo_num);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
	pthread_mutex_lock(&philo->m_time_to_last_eaten);
	philo->time_to_last_eaten = get_time();
	pthread_mutex_unlock(&philo->m_time_to_last_eaten);
	pass_time(philo->table->time_to_eat);
	philo->eat_count++;
	if (philo->eat_count == philo->table->eat_count)
	{
		pthread_mutex_lock(&philo->m_is_full);
		philo->is_full = 1;
		pthread_mutex_unlock(&philo->m_is_full);
	}
}

void	go_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		printf("%lld %d is sleeping\n", \
		get_time_table(philo->table->start_time), philo->philo_num);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
	pass_time(philo->table->time_to_sleep);
}

void	go_to_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
		printf("%lld %d is thinking\n", \
		get_time_table(philo->table->start_time), philo->philo_num);
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
}

void	go_to_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	printf("%lld %d died\n", \
	get_time_table(philo->table->start_time), philo->philo_num);
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
}
