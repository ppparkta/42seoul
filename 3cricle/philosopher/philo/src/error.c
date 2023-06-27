/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 08:51:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 21:45:50 by sooyang          ###   ########.fr       */
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
	int	i;

	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->m_is_full);
	pthread_mutex_destroy(&table->m_is_dead);
	i = 0;
	while (i < table->philo_head)
	{
		pthread_mutex_destroy(&(table->fork[i]));
		i++;
	}
	i = 0;
	while (i < table->philo_head)
	{
		pthread_mutex_destroy(&(table->m_last_eaten[i]));
		i++;
	}
}

int	mutex_error(t_table *table, char *message)
{
	destroy_mutex(table);
	print_error_message(message);
	return (1);
}

int	error(t_philo *philo, char *message)
{
	destroy_mutex(philo->table);
	free(philo->table->fork);
	free(philo->table->m_last_eaten);
	free(philo);
	print_error_message(message);
	return (1);
}
