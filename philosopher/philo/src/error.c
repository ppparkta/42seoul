/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 08:51:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 19:29:05 by sooyang          ###   ########.fr       */
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
	pthread_mutex_destroy(&table->m_is_full);
	pthread_mutex_destroy(&table->m_is_dead);
	i = -1;
	while (++i < table->philo_head)
		pthread_mutex_destroy(&(table->m_time_to_last_eaten[i]));
}

int	mutex_error(t_philo *philo, char *message)
{
	destroy_mutex(philo->table);
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
