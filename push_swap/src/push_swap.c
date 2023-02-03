/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:44 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/02 21:50:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	check_sorted(t_stack *stack)
{
	t_node	*cursor;

	cursor = stack->head;
	while (cursor != stack->tail)
	{
		if (cursor->next->index < cursor->index)
			break;
		cursor = cursor->next;
	}
	if (cursor == stack->tail)
		exit(0);
}

void print_index(t_stack *stack)
{
	t_node *node;
	int i = 0;
	node=stack->head;
	while(i<stack->size)
	{
		printf("%d\n", node->index);
		node=node->next;
		i++;
	}
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
	print_index(a_stack);
	//if (a_stack->size < 6)
	//	return (0);
	swap_a_to_b(a_stack, b_stack);
	swap_b_to_a(a_stack, b_stack);
	return (0);
}
