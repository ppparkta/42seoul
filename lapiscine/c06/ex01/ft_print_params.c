/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:47:59 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/27 13:25:51 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
