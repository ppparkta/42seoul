/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:44 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/31 18:13:59 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	wrong_format(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	char	**arg;
	int		i;
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (argc < 2)
		exit(0);
	a_stack = init();
	b_stack = init();
	i = 0;
	while (++i < argc)
	{
		arg = ft_split(argv[i], ' ');
		parsing(a_stack, i, arg);
		free(arg);
	}
	return (0);
}
