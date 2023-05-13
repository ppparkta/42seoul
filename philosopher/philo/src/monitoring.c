/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:28:05 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 22:28:25 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_die(t_philo *philo, t_table *table)
{
	int		i;
	long	now;
	long	last_eaten;

	i = 0;
	while (i < table->philo_head)
	{
		pthread_mutex_lock(&table->m_last_eaten[i]);
		last_eaten = philo[i].last_eaten;
		pthread_mutex_unlock(&table->m_last_eaten[i]);
		now = get_time();
		if (now - last_eaten > table->time_to_die)
		{
			pthread_mutex_lock(&table->m_is_dead);
			table->is_dead = 1;
			pthread_mutex_unlock(&table->m_is_dead);
			pthread_mutex_lock(&table->print);
			printf("%llu %d %s\n", now - table->start_time, philo[i].philo_num, "died");
			pthread_mutex_unlock(&(philo->table->print));
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	while (1)
	{
		if (check_die(philo, table))
			break ;
		pthread_mutex_lock(&table->m_is_full);
		if (table->eat_count != 0 && table->is_full == table->philo_head)
		{
			pthread_mutex_unlock(&table->m_is_full);
			pthread_mutex_lock(&table->m_is_dead);
			table->is_dead = 1;
			pthread_mutex_unlock(&table->m_is_dead);
			break ;
		}
		pthread_mutex_unlock(&table->m_is_full);
		usleep(100);
	}
	return (0);
}
