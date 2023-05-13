/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:24:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:21:31 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_up_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[philo->fork_left]);
	info->fork_list[philo->fork_left] = 1;
	print_philo(info, philo->id, FORK);
	pthread_mutex_lock(&info->fork[philo->fork_right]);
	info->fork_list[philo->fork_right] = 1;
	print_philo(info, philo->id, FORK);
}

void	put_down_fork(t_info *info, t_philo *philo)
{
	info->fork_list[philo->fork_left] = 0;
	pthread_mutex_unlock(&info->fork[philo->fork_left]);
	info->fork_list[philo->fork_right] = 0;
	pthread_mutex_unlock(&info->fork[philo->fork_right]);
}
