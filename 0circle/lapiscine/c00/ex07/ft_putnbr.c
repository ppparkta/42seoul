/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:25:06 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/23 14:30:44 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	itoc(long long nb)
{
	char	i;

	if (nb < 0)
	{
		write(1, "-", 1);
		itoc(-nb);
		return ;
	}
	if (nb >= 10)
	{
		itoc(nb / 10);
	}
	i = nb % 10 + '0';
	write(1, &i, 1);
}

void	ft_putnbr(int nb)
{
	long long	number;

	number = (long long)nb;
	itoc(number);
}
