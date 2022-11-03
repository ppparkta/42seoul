/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:15:40 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/01 15:32:06 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"ft_stock_str.h"

void	itoa(int size)
{
	char	temp;

	if (size > 9)
	{
		itoa(size / 10);
	}
	temp = (size % 10) + '0';
	write(1, &temp, 1);
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_print(par[i].str);
		itoa(par[i].size);
		write(1, "\n", 1);
		ft_print(par[i].copy);
		i++;
	}
}

/*
#include	<stdio.h>
#include	<stdlib.h>
int	main(int ac, char **av)
{
	printf("----ex04, ex05----\n\n");
	struct s_stock_str *str;
	str = ft_strs_to_tab(ac, av);

	ft_show_tab(str);
	write(1, "\n", 1);
	free(str);
	return (0);
}*/
