/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:30:27 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/10 13:34:18 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->all_fork[philo->left_fork]);
	if (check_dead(philo->table))
		print_msg(philo, " has taken a fork\n");
	pthread_mutex_lock(&philo->table->all_fork[philo->right_fork]);
	if (check_dead(philo->table))
		print_msg(philo, " has taken a fork\n");
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->all_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->all_fork[philo->right_fork]);
}
