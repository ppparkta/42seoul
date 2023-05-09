/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_enter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/09 15:05:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 철학자가 단 한명일 때 예외처리
void philo_only_one(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%d %d has taken a fork\n", 0, \
		philo->philo_num);
}

//죽은 사람 있는지 확인
int	check_dead(t_table *table)
{
	int	swc;

	pthread_mutex_lock(&table->m_is_dead);
	swc = table->is_dead;
	pthread_mutex_unlock(&table->m_is_dead);
	return (swc);
}

// 철학자 생명주기
void *philo_life_cycle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("my number is %d\n", philo->philo_num);
	if (philo->table->philo_head == 1)
	{
		philo_only_one(philo);
		return (0);
	}
	if (philo->philo_num % 2 == 0)
		usleep(philo->table->time_to_eat * 500);
	while (philo->is_full == 0 && check_dead(philo->table) == 0)
	{
		if (check_dead(philo->table) == 1)
			break ;
		pick_up_fork(philo);
		if (check_dead(philo->table) == 1)	
		{
			put_down_fork(philo);
			break ;
		}
		go_to_eat(philo);
		put_down_fork(philo);
		if (check_dead(philo->table) == 1)
			break ;
		go_to_sleep(philo);
		if (check_dead(philo->table) == 1)
			break ;
		go_to_think(philo);
	}
	return (0);
}

/*시간설정할 때 항상 같은 시간에서 시작해야 시간순서가 꼬이지 않기 때문에 뮤텍스로 테이블 전체를 보호해줌
table mutex_lock*/
int philo_enter(t_table *table, t_philo *philo)
{
	printf("philo start\n");
	int	i;

	i = -1;
	pthread_mutex_lock(&table->m_is_dead);
	while (++i < table->philo_head)
		pthread_create(&philo[i].thread, NULL, philo_life_cycle, &philo[i]);
	set_time(table, philo);
	pthread_mutex_unlock(&table->m_is_dead);
	return (1);
}
