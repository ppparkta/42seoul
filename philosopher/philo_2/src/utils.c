/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:14:33 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:34:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i]));
	pthread_mutex_destroy(&(info->m_is_died));
	pthread_mutex_destroy(&(info->m_is_full));
	pthread_mutex_destroy(&(info->m_last_eaten));
	pthread_mutex_destroy(&(info->print));
}

int	ft_usleep(int sleep_utime)
{
	struct timeval	start_time;
	struct timeval	now_time;

	if (gettimeofday(&start_time, NULL) < 0)
		return (printf("get time error.\n"));
	while (1)
	{
		if (gettimeofday(&now_time, NULL) < 0)
			return (printf("get time error.\n"));
		if ((now_time.tv_usec - start_time.tv_usec) > sleep_utime)
			break ;
	}
	return (0);
}

long long	init_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) < 0)
		return (printf("get time error.\n"));
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void	pass_time(t_philo *philo, int time)
{
	long long	start;

	start = init_time();
	while ((init_time() - start < time))
	{
		if ((long long)philo->info->time_to_die < \
		init_time() - philo->last_eaten)
			break ;
		usleep(150);
	}
}

void	print_philo(t_info *info, int id, int status)
{
	long long	now_time;

	pthread_mutex_lock(&(info->print));
	now_time = init_time() - info->start_time;
	if (!check_death(info))
	{
		if (status == FORK)
			printf("%lld %d has taken a fork\n", now_time, id);
		else if (status == EAT)
			printf("%lld %d is eating\n", now_time, id);
		else if (status == SLEEP)
			printf("%lld %d is sleeping\n", now_time, id);
		else if (status == THINK)
			printf("%lld %d is thinking\n", now_time, id);
		else if (status == DIE)
		{
			printf("%lld %d died\n", now_time, id);
			pthread_mutex_lock(&(info->m_is_died));
			info->is_died = 1;
			pthread_mutex_unlock(&(info->m_is_died));
		}
	}
	pthread_mutex_unlock(&(info->print));
}
