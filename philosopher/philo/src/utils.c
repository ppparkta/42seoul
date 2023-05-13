/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:14:33 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 19:19:11 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_act(t_philo *philo, char *msg)
{
	long long	time;

	time = get_time();
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead)
	{
		if (strcmp(msg, "eating") == 0 || strcmp(msg, "has taken a fork") == 0)
		{
			pthread_mutex_unlock(&philo->table->all_fork[philo->left_fork]);
			pthread_mutex_unlock(&philo->table->all_fork[philo->right_fork]);
		}
		pthread_mutex_unlock(&philo->table->print);
		pthread_mutex_unlock(&philo->table->m_is_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->m_is_dead);
	printf("%lld %d %s\n", (time - philo->table->start_time), \
	philo->philo_num, msg);
	pthread_mutex_unlock(&philo->table->print);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (i < str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	ans;

	i = 0;
	ans = 0;
	if (ft_strlen(str) >= 11)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' )
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			ans = (ans * 10) + (str[i] - '0');
			i++;
		}
		return ((int)ans);
	}
	return (0);
}
