/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:44 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/13 13:35:39 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_sorted(t_stack *stack)
{
	t_node	*cursor;

	cursor = stack->head;
	while (cursor != stack->tail)
	{
		if (cursor->next->index < cursor->index)
			break ;
		cursor = cursor->next;
	}
	if (cursor == stack->tail)
		exit(0);
}

void	wrong_format(void)
{
	ft_putstr_fd("Error", 2);
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
	a_stack = stack_init();
	b_stack = stack_init();
	i = 0;
	while (++i < argc)
	{
		arg = ft_split(argv[i], ' ');
		parsing(a_stack, i, arg);
		free(arg);
	}
	check_sorted(a_stack);
	if (a_stack->size < 6)
		less_swap(a_stack, b_stack);
	swap_a_to_b(a_stack, b_stack);
	swap_b_to_a(a_stack, b_stack);
	exit(0);
}
