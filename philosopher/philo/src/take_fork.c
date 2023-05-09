/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:30:27 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 22:09:59 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->all_fork[philo->left_fork]);
	print_msg(philo, " has taken a fork\n");
	//pthread_mutex_unlock(&philo->table->m_is_dead);
	pthread_mutex_lock(&philo->table->all_fork[philo->right_fork]);
	//pthread_mutex_lock(&philo->table->m_is_dead);
	//if (philo->table->is_dead == 0)
		print_msg(philo, " has taken a fork\n");
	//pthread_mutex_unlock(&philo->table->m_is_dead);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->all_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->all_fork[philo->right_fork]);
}
