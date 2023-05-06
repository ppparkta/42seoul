/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:44:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/07 00:47:42 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//void	philo_behavior(t_philo *philo, int swc)
//{
//	pthread_mutex_lock(&philo->table->print);
//	pthread_mutex_lock(&philo->table->m_is_dead);
//	if (philo->table->is_dead == 0)
//	{
		
//	}
//	pthread_mutex_unlock(&philo->table->m_is_dead);
//	pthread_mutex_unlock(&philo->table->print);
//}

//밥먹기
void	go_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		printf("%d %d is eating\n", get_time_table(philo->table->start_time), \
		philo->philo_num);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
}

//잠자기
void	go_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		printf("%d %d is sleeping\n", get_time_table(philo->table->start_time), \
		philo->philo_num);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
}

//생각하기
void	go_to_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
		printf("%d %d is thinking\n", get_time_table(philo->table->start_time), \
		philo->philo_num);
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
}