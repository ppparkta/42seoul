/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:14:33 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 21:46:39 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_log(t_philo *philo, char *message)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(&(philo->table->print));
	pthread_mutex_lock(&(philo->table->m_is_dead));
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&(philo->table->print));
		pthread_mutex_unlock(&(philo->table->m_is_dead));
		return (1);
	}
	pthread_mutex_unlock(&(philo->table->m_is_dead));
	printf("%llu %d %s\n", time - philo->table->start_time, \
	philo->philo_num, message);
	pthread_mutex_unlock(&(philo->table->print));
	return (0);
}

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str, t_table *table)
{
	int		minus;
	long	num;

	num = 0;
	minus = 1;
	while (*str == ' ')
		str++;
	if (ft_strlen(str) > 11)
		table->error = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	if (!(47 < *str && *str < 58))
		table->error = 1;
	while (47 < *str && *str < 58)
		num = 10 * num + *str++ - '0';
	if (*str)
		table->error = 1;
	num *= minus;
	if (num > 2147483647 || num < -2147483648)
		table->error = 1;
	return (num);
}
