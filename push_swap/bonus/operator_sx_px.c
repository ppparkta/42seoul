/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_sx_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:48 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/08 14:41:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void sx(t_stack *s, char *msg)
{
	int	tmp_i;
	int	tmp_j;

	if (s->size >= 2)
	{
		tmp_i = s->head->data;
		tmp_j = s->head->index;
		s->head->data = s->head->next->data;
		s->head->index = s->head->next->index;
		s->head->next->data = tmp_i;
		s->head->next->index = tmp_j;
	}
	if (msg)
		ft_putstr_fd(msg, 1);
}

void ss(t_stack *a, t_stack *b, char *msg)
{
	sx(a, NULL);
	sx(b, NULL);
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*node;

	if (stack_b->head != NULL)
	{
		node = pop(stack_b);
		if (stack_a->head == NULL)
		{
			node->prev = node;
			node->next = node;
			stack_a->head = node;
			stack_a->tail = node;
		}
		else
		{
			node->next = stack_a->head;
			node->prev = stack_a->tail;
			stack_a->tail->next = node;
			stack_a->head->prev = node;
			stack_a->head = node;
		}
	}
	//if (stack_a->head == stack_b->head)
	//	stack_element_init(stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_a->head != NULL)
	{
		node = pop(stack_a);
		if (stack_b->head == NULL)
		{
			node->prev = node;
			node->next = node;
			stack_b->head = node;
			stack_b->tail = node;
		}
		else
		{
			node->next = stack_b->head;
			node->prev = stack_b->tail;
			stack_b->tail->next = node;
			stack_b->head->prev = node;
			stack_b->head = node;
		}	
	}
	//if (stack_a->top == stack_b->top)
	//	stack_element_init(stack_a);
}