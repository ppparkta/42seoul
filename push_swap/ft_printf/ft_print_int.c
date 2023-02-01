/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:12:30 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/31 16:29:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print_d(int n)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_print_d((int)(nb / 10));
		len += ft_print_d((int)(nb % 10));
	}
	else
	{
		len += ft_print_c((int)(nb + (long long)'0'));
	}
	return (len);
}

int	ft_print_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_print_u(n / 10);
		len += ft_print_u(n % 10);
	}
	else
	{
		if (n <= 9)
			len += ft_print_c(n + (int)'0');
	}
	return (len);
}

int	ft_print_x(unsigned int n, int s)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_x(n / 16, s);
		len += ft_print_x(n % 16, s);
	}
	else
	{
		if (n < 10)
			len += ft_print_c(n + (int)'0');
		else
		{
			if (s == 1)
				len += ft_print_c(n + 55);
			if (s == 2)
				len += ft_print_c(n + 87);
		}
	}
	return (len);
}

int	ft_print_p(unsigned long long int n)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_print_p(n / 16);
		len += ft_print_p(n % 16);
	}
	else
	{
		if (n < 10)
			len += ft_print_c(n + (int)'0');
		else
			len += ft_print_c(n + 87);
	}
	return (len);
}

int	ft_print_s(char *s)
{
	int	len;

	len = 0;
	if (s == 0)
		s = "(null)";
	while (*s)
	{
		len += write(1, s, 1);
		s++;
	}
	return (len);
}
