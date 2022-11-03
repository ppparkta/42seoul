/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:46:39 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 00:08:29 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdio.h>

int	fstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	notation(long long n, int nota, char *base)
{
	int	a;

	if (n < 0)
	{
		write(1, "-", 1);
		notation(-n, nota, base);
		return ;
	}
	if (n >= nota)
		notation(n / nota, nota, base);
	a = n % nota;
	write(1, base + a, 1);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		no;
	int		o;
	int		i;
	int		k;
	int		alpha[256];

	i = 0;
	while (i < 256)
		alpha[i++] = 0;
	o = 0;
	no = fstrlen(base);
	if (no < 2)
		return ;
	while (base[o] != '\0')
	{
		k = base[o];
		if (alpha[k] == 1)
			return ;
		if (base[o] == '+' || base[o] == '-')
			return ;
		alpha [k] = 1;
		o++;
	}
	notation(nbr, no, base);
}

/*int	main(void)
{
	//ex04
	printf("------ ex04 ------\n");
	printf("-bmLbpjci\n");
	ft_putnbr_base(-2147483648, "abcdEFGhijkLNmopqrST");
	printf("\n\n");
	printf("*///////\n");
/*	ft_putnbr_base(2147483647, "!@#$%^&*()<>,.?/");
	printf("\n\n");
	printf("-)()()(\n");
	ft_putnbr_base(-42, "()");
	printf("\n\n");
	printf("[SHOULD NOT PRINT]\n");
	ft_putnbr_base(133316, "");
	printf("\n\n");
	printf("[SHOULD NOT PRINT]\n");
	ft_putnbr_base(15361, "aabc!");
	printf("\n\n");
	printf("59483\n");
	ft_putnbr_base(59483, "0123456789");
	printf("\n\n");
}*/
