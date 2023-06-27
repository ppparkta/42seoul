/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:21:49 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 20:27:05 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_time(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	table->start_time = get_time();
	while (++i < table->philo_head)
		philo[i].time_to_last_eaten = table->start_time;
}

long long	get_time_table(long long check_time)
{
	long long	now;

	now = get_time();
	return (now - check_time);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	pass_time(long long time, t_philo *philo)
{
	long long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time)
	{
		pthread_mutex_lock(&philo->table->m_is_dead);
		if (philo->table->is_dead == 1)
		{
			pthread_mutex_unlock(&philo->table->m_is_dead);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->m_is_dead);
		usleep(100);
	}
	return (0);
}