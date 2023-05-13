/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 08:44:58 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 23:49:51 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*one_philo(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[0]);
	info->fork_list[0] = 1;
	print_philo(info, philo->id, FORK);
	while (1)
	{
		if (check_death(info))
		{
			info->fork_list[0] = 0;
			pthread_mutex_unlock(&info->fork[0]);
			return (0);
		}
		usleep(250);
	}
	return (0);
}

void	change_die_flag(t_info *info)
{
	pthread_mutex_lock(&(info->m_is_died));
	info->is_died = 1;
	pthread_mutex_unlock(&(info->m_is_died));
}

void	set_last_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->m_last_eaten));
	philo->last_eaten = init_time();
	pthread_mutex_unlock(&(info->m_last_eaten));
}

void	set_full_philo(t_info *info)
{
	if (info->eat_count == -1)
		return ;
	pthread_mutex_lock(&(info->m_is_full));
	info->is_full += 1;
	pthread_mutex_unlock(&(info->m_is_full));
}
