/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:51 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/08 14:43:37 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	init_node(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		wrong_format();
	init_node(stack);
	return (stack);
}

void	push(t_stack *s, int data, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		wrong_format();
	node->data = data;
	node->index = index;
	if (s->size == 0)
	{
		node->prev = node;
		node->next = node;
		s->head = node;
		s->tail = node;
	}
	else
	{
		node->next = s->head;
		node->prev = s->tail;
		s->head->prev = node;
		s->tail->next = node;
		s->head = node;
	}
	s->size++;
}

void	first_push(t_stack *s, int data, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		wrong_format();
	node->data = data;
	node->index = index;
	if (s->size == 0)
	{
		node->prev = node;
		node->next = node;
		s->head = node;
		s->tail = node;
	}
	else
	{
		node->prev = s->tail;
		node->next = s->head;
		s->tail->next = node;
		s->head->prev = node;
		s->tail = node;
	}
	s->size++;
}

t_node	*pop(t_stack *s)
{
	t_node	*tmp;

	s->size--;
	tmp = s->head;
	s->head = s->head->next;
	s->head->prev = s->tail;
	s->tail->next = s->head;
	return (tmp);
}
