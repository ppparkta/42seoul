/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:43:05 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/29 19:55:52 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	startprint(long long adr)
{
	char	start[16];
	int		i;

	i = 15;
	while (i >= 0)
	{
		start[i--] = "0123456789abcdef"[adr % 16];
		adr /= 16;
	}
	write(1, start, 16);
}

void	put_16print(char a)
{
	int		s;
	char	t;
	char	o;

	s = (int)a;
	t = "0123456789abcdef"[s / 16];
	o = "0123456789abcdef"[s % 16];
	write(1, &t, 1);
	write(1, &o, 1);
}

void	middleprint(void *string, int line, int size)
{
	int				j;
	unsigned char	temp;

	j = 0;
	while (j < 16)
	{
		if (j + line * 16 >= size)
		{
			while (j < 16)
			{
				write(1, "  ", 2);
				if (j % 2 != 0)
					write(1, " ", 1);
				j++;
			}
			return ;
		}
		temp = ((unsigned char *)string)[j + (16 * line)];
		put_16print(temp);
		if (j % 2 != 0)
			write(1, " ", 1);
		j++;
	}
}

void	endprint(void *string, int line, int size)
{
	int		i;
	char	*temp;

	temp = (char *)string;
	i = 0;
	while (i < 16)
	{
		if (i + line * 16 >= size)
			return ;
		if (!(temp[i + line * 16] >= 32 && temp[i + line * 16] <= 126))
		{
			write(1, ".", 1);
		}
		if (temp[i + line * 16] >= 32 && temp[i + line * 16] <= 126)
		{
			write(1, &temp[i + line * 16], 1);
		}
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long int	adr;
	int						a;
	int						line;

	adr = (long long)addr;
	a = 0;
	line = 0;
	if (size % 16 == 0)
		line = size / 16;
	else
		line = size / 16 + 1;
	while (a < line)
	{
		startprint(adr + (a * 16));
		write(1, ":", 1);
		write(1, " ", 1);
		middleprint(addr, a, size);
		endprint(addr, a, size);
		write(1, "\n", 1);
		a++;
	}
}
