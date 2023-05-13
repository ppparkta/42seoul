/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 08:51:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 09:43:32 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error_message(char *message)
{
	printf("%s\n", message);
	return (1);
}

void	destroy_mutex(t_table *table)
{
	int		i;

	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->m_is_dead);
	pthread_mutex_destroy(&table->m_is_full);
	i = -1;
	while (++i < table->philo_head)
		pthread_mutex_destroy(&(table->all_fork[i]));
	i = -1;
	while (++i < table->philo_head)
		pthread_mutex_destroy(&(table->m_time_to_last_eaten[i]));
}

int	mutex_error(t_table *table, char *message)
{
	destroy_mutex(table);
	print_error_message(message);
	return (1);
}

int	error_all(t_philo *philo, char *message)
{
	destroy_mutex(philo->table);
	free(philo->table->all_fork);
	free(philo->table->m_time_to_last_eaten);
	free(philo);
	print_error_message(message);
	return (1);
}