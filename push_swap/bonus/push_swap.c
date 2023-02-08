/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:44 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/08 14:36:43 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"
#include <stdio.h>

void	wrong_format(void)
{
	ft_putstr_fd("Error", 2);
	exit(0);
}

void stack_print(t_stack *stack)
{
	t_node	*node;
	
	node = stack->head;
	while (node != stack->tail)
	{
		printf("%d\n",node->data);
		node=node->next;
	}
	printf("%d\n",node->data);
}

int	main(int argc, char **argv)
{
	char	**arg;
	char	*operator;
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
	stack_print(a_stack);
	while (1)
	{
		operator = get_next_line(0);
		if (!operator)
			break;
		checker(operator, a_stack, b_stack);
		printf("a satck size: %d\n", a_stack->size);
		printf("b satck size: %d\n", b_stack->size);
		stack_print(a_stack);
	}
	stack_print(a_stack);
	check_sorted(a_stack, b_stack);
	exit(0);
	return (0);
}
