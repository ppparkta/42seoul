/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:28:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:05:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_death(t_info *info)
{
	int	die;

	pthread_mutex_lock(&(info->m_is_died));
	die = info->is_died;
	pthread_mutex_unlock(&(info->m_is_died));
	return (die);
}

int	check_end(t_info *info, t_philo *philo, int i)
{
	if (info->eat_count != -1)
	{
		pthread_mutex_lock(&(info->m_is_full));
		if (info->is_full == info->philo_num)
		{
			change_die_flag(info);
			return (1);
		}
		pthread_mutex_unlock(&(info->m_is_full));
	}
	pthread_mutex_lock(&(info->m_last_eaten));
	if ((long long)info->time_to_die < init_time() - philo[i].last_eaten)
	{
		print_philo(info, philo[i].id, DIE);
		pthread_mutex_unlock(&(info->m_last_eaten));
		change_die_flag(info);
		return (1);
	}
	pthread_mutex_unlock(&(info->m_last_eaten));
	return (0);
}

void	*monitoring(void *philos)
{
	t_philo	*philo;
	t_info	*info;
	int		i;

	philo = (t_philo *)philos;
	info = philo->info;
	i = -1;
	while (1)
	{
		if (++i >= info->philo_num)
			i = 0;
		if (check_end(info, philo, i))
			break ;
	}
	return (0);
}
