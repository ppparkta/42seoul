/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_enter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/06 04:14:37 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *philo_life_cycle(t_philo *philo)
{
	//짝수예외처리
	//먹기
	//자기
	//생각하기
}

void set_time(t_table *table, t_philo *philo)
{
	int i;

	i = -1;
	table->start_time = get_time();
	while (++i < table->philo_head)
		philo[i].time_to_last_eaten = table->start_time;
}

int get_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
}

int philo_enter(t_table *table, t_philo *philo)
{
	int i;

	i = -1;
	while (++i < table->philo_head)
	{
		// 쓰레드 생성
		pthread_create(&philo[i].thread, NULL, philo_life_cycle, &philo[i]);
	}
	// 시간 설정
	// mutex_lock
	set_time(table, philo);
	// mutex_unlock
	return (0);
}