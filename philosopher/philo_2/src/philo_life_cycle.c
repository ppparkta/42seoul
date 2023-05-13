/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:26:53 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eat_philo(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pick_up_fork(info, philo);
	if (check_death(info))
	{
		put_down_fork(info, philo);
		return (1);
	}
	print_philo(philo->info, philo->id, EAT);
	set_last_eat(info, philo);
	pass_time(philo, info->time_to_eat);
	put_down_fork(info, philo);
	philo->eat_count += 1;
	if (philo->eat_count == info->eat_count)
		set_full_philo(info);
	return (0);
}

void	*philo_life_cycle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->info->philo_num == 1)
		return (one_philo(philo->info, philo));
	if (philo->id % 2 == 0)
		usleep(250);
	while (1)
	{
		if (check_death(philo->info))
			break ;
		if (eat_philo(philo))
			break ;
		if (check_death(philo->info) || \
		philo->eat_count == philo->info->eat_count)
			break ;
		print_philo(philo->info, philo->id, SLEEP);
		pass_time(philo, philo->info->time_to_sleep);
		if (check_death(philo->info))
			break ;
		print_philo(philo->info, philo->id, THINK);
		usleep(250);
	}
	return (0);
}

void	run(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	info->start_time = init_time();
	while (++i < info->philo_num)
	{
		philo[i].last_eaten = init_time();
		if (pthread_create(&philo[i].thread, NULL, philo_life_cycle, &philo[i]))
			return ;
	}
	if (pthread_create(&info->monitor_thread, NULL, monitoring, philo))
		return ;
	pthread_join(info->monitor_thread, NULL);
	i = -1;
	while (++i < info->philo_num)
		pthread_join(philo[i].thread, NULL);
	return ;
}
