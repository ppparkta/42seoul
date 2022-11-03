/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:19:36 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/18 22:23:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int n)
{
	char	f;
	char	b;

	b = n % 10 + '0';
	f = n / 10 + '0';
	write(1, &f, 1);
	write(1, &b, 1);
}

void	ft_print_comb2(void)
{
	int	n;
	int	m;

	n = 0;
	while (n <= 97)
	{
		m = n + 1;
		while (m <= 99)
		{
			print_num(n);
			write(1, " ", 1);
			print_num(m);
			write(1, ", ", 2);
			m++;
		}
		n++;
	}
	write(1, "98 99", 5);
}
