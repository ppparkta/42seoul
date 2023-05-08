/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:30:27 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/08 16:11:33 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%lld %d has taken a left fork\n",
		get_time_table(philo->table->start_time), philo->philo_num);
	pthread_mutex_lock(philo->right_fork);
	printf("%lld %d has taken a right fork\n",
		get_time_table(philo->table->start_time), philo->philo_num);
}

void put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("%lld %d has put down a fork\n",
		get_time_table(philo->table->start_time), philo->philo_num);
}