/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:44:19 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 20:31:03 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == 0)
	{
		pthread_mutex_lock(&philo->table->print);
		printf("%lld %d%s", get_time_table(philo->table->start_time), \
		philo->philo_num, msg);
		pthread_mutex_unlock(&philo->table->print);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
}

void	go_to_eat(t_philo *philo)
{
	pick_up_fork(philo);
	print_msg(philo, " is eating\n");
	pthread_mutex_lock(&philo->m_time_to_last_eaten);
	philo->time_to_last_eaten = get_time();
	pthread_mutex_unlock(&philo->m_time_to_last_eaten);
	pass_time(philo->table->time_to_eat, philo);
	philo->eat_count++;
	if (philo->eat_count == philo->table->eat_count)
	{
		pthread_mutex_lock(&philo->m_is_full);
		philo->is_full = 1;
		pthread_mutex_unlock(&philo->m_is_full);
	}
	put_down_fork(philo);
}

void	go_to_sleep(t_philo *philo)
{
	print_msg(philo, " is sleeping\n");
	pass_time(philo->table->time_to_sleep, philo);
}
