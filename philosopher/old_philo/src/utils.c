/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:14:33 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 20:25:41 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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