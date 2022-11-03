/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:39:24 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/01 19:51:08 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_stock_str.h"

int	leng(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*test;
	int			i;
	int			j;

	test = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(test))
		return (0);
	i = 0;
	while (i < ac)
	{
		test[i].size = leng(av[i]);
		test[i].str = av[i];
		test[i].copy = (char *)malloc(sizeof(char) * test[i].size + 1);
		j = 0;
		while (j < test[i].size)
		{
			test[i].copy[j] = test[i].str[j];
			j++;
		}
		test[i].copy[j] = '\0';
		i++;
	}
	test[i].str = 0;
	return (test);
}
