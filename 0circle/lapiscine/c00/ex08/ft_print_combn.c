/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:41:47 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/19 10:42:24 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	mk_int(int num, int n)
{
	if (n == 1)
	{
		ft_putchar(num + '0');
		return ;
	}
	mk_int(num / 10, n - 1);
	ft_putchar(num % 10 + '0');
}
void	ft_combn(int comb, int cur, int n)
{
	int	index;

	if (cur > n)
	{
		if (comb % 10 != n - 1)
			write(1, ", ", 2);
		mk_int(comb, n);
		return ;
	}
	if (cur == 1)
		index = 0;
	else
		index = comb % 10 + 1;
	while (index < 10)
	{
		ft_combn(comb * 10 + index, cur + 1, n);
		index++;
	}
}
void	ft_print_combn(int n)
{
	ft_combn(0, 1, n);
}*/
int	dfsn(int depth, int num, int n, char *arr)
{
	if (depth == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
		return (0);
	}
	else
	{
		while (num <= 9)
		{
			arr[depth] = num + '0';
			num++;
			dfsn(depth + 1, num, n, arr);
		}
	}
	return (0);
}

void	ft_print_combn(int n)
{
	char	arr[9];

	dfsn(0, 0, n, arr);
}
