/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:56:34 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:52:50 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	hexa(int al)
{
	unsigned char	t;
	unsigned char	o;

	t = (unsigned char)"0123456789abcdef"[al / 16];
	o = (unsigned char)"0123456789abcdef"[al % 16];
	write(1, "\\", 1);
	write(1, &t, 1);
	write(1, &o, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char *)str;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] < 32 || a[i] > 126)
			hexa(a[i]);
		else
			write(1, &a[i], 1);
		i++;
	}
}

/*
#include	<stdio.h>
#include	<string.h>

int main(void)
{
	char s1[]="Coucou\ntu vas bien ?";
	ft_putstr_non_printable(s1);
}*/
