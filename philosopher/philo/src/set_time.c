/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:21:49 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/07 00:40:18 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 시간시간설정하기
void set_time(t_table *table, t_philo *philo)
{
	int i;

	i = -1;
	table->start_time = get_time();
	while (++i < table->philo_head)
		philo[i].time_to_last_eaten = table->start_time;
}

//테이블시간가져오기
int	get_time_table(int check_time)
{
	int	now;

	now = get_time();
	return (now - check_time);
}

// 현재시간가져오기
int get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
