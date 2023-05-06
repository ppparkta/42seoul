/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_enter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:55:28 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/07 02:56:25 by sooyang          ###   ########.fr       */
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
int	check_dead(t_philo *philo)
{
	int	swc;

	pthread_mutex_lock(&philo->table->m_is_dead);
	swc = philo->table->is_dead;
	pthread_mutex_unlock(&philo->table->m_is_dead);
	return (swc);
}

// 철학자 생명주기
void *philo_life_cycle(void *data)
{
	printf("new thread generate\n");
	t_philo	*philo;

	philo = (t_philo *)data;
	//한명일때 예외처리
	printf("hi %d\n", philo->table->philo_head);
	printf("hi %d\n", philo->is_full);
	printf("my number is %d\n", philo->philo_num);
	if (philo->table->philo_head == 1)
	{
		philo_only_one(philo);
		return (0);
	}
	// 짝수예외처리
	if (philo->philo_num % 2 == 0)
		usleep(philo->table->time_to_eat * 500);
	// 죽거나 배부른 사람 없으면 평생 돌아감
	while (philo->is_full == 0 && check_dead(philo) == 0)
	{
		pick_up_fork(philo);
		go_to_eat(philo);
		put_down_fork(philo);
		go_to_sleep(philo);
		go_to_think(philo);
	}
	return (0);
}

/*시간설정할 때 항상 같은 시간에서 시작해야 시간순서가 꼬이지 않기 때문에 뮤텍스로 테이블 전체를 보호해줌
table mutex_lock*/
int philo_enter(t_table *table, t_philo *philo)
{
	printf("philo start\n");
	int i;

	i = -1;
	pthread_mutex_lock(&table->m_is_dead);
	while (++i < table->philo_head)
		pthread_create(&philo[i].thread, NULL, philo_life_cycle, &philo[i]);
	set_time(table, philo);
	pthread_mutex_unlock(&table->m_is_dead);
	return (1);
}
