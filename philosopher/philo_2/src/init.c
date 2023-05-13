/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:53:38 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:05:26 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
		return (1);
	i = -1;
	while (++i < info->philo_num)
	{
		(*philo)[i].id = i + 1;
		if (i == 0)
			(*philo)[i].fork_right = info->philo_num - 1;
		else
			(*philo)[i].fork_right = i - 1;
		(*philo)[i].fork_left = i;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
	}
	return (0);
}

int	init_info(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!info->fork)
		return (printf("malloc error\n"));
	if ((pthread_mutex_init(&info->m_is_died, NULL)) != 0)
		return (-1);
	if ((pthread_mutex_init(&info->m_is_full, NULL)) != 0)
		return (-1);
	if ((pthread_mutex_init(&info->m_last_eaten, NULL)) != 0)
		return (-1);
	if ((pthread_mutex_init(&info->print, NULL)) != 0)
		return (-1);
	i = -1;
	while (++i < info->philo_num)
	{
		if ((pthread_mutex_init(&info->fork[i], NULL)) != 0)
			return (-1);
	}
	return (0);
}

int	set_info(t_info *info, char **argv)
{
	int	i;

	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->philo_num < 1 || info->time_to_die < 1 \
	|| info->time_to_eat < 1 || info->time_to_sleep < 1)
		return (1);
	if (argv[5])
	{
		info->eat_count = ft_atoi(argv[5]);
		if (info->eat_count < 1)
			return (1);
	}
	else
		info->eat_count = -1;
	info->is_full = 0;
	info->is_died = 0;
	i = -1;
	while (++i < info->philo_num)
		info->fork_list[i] = 0;
	return (0);
}
