/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:21:49 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 13:18:06 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	pass_time(t_philo *philo, long long time)
{
	long long	start;
	long long	now;

	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start >= time)
			return ;
		pthread_mutex_lock(&philo->table->m_is_dead);
		if (philo->table->is_dead)
		{
			pthread_mutex_unlock(&philo->table->m_is_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->table->m_is_dead);
		usleep(100);
	}
}
