/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:30:27 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 16:46:19 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		printf("%lld %d has taken a left fork\n",
			get_time_table(philo->table->start_time), philo->philo_num);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		printf("%lld %d has taken a right fork\n",
			get_time_table(philo->table->start_time), philo->philo_num);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_unlock(&philo->table->print);
}

void put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}