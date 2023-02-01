/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:51 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/31 18:14:30 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	init_node(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
}

t_stack	*init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(0);
	init_node(stack);
	return (stack);
}

void	push(t_stack *s, int data)
{
	t_node	*node;

	node=(t_node *)malloc(sizeof(t_node));
	if (!node)
		wrong_format();
	s->size++;
	node->data = data;
	node->index = 0;
	if (s->size==0)
	{
		s->head=node;
		s->tail=node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		s->head->prev=node;
		node->next=s->head;
		s->head=node;
	}
}

int	pop(t_stack *s)
{
	int		n;
	t_node	*tmp;

	s->size--;
	n = s->head->data;
	tmp = s->head;
	s->head = s->head->next;
	s->head->prev = s->tail;
	s->tail->next = s->head;
	free(tmp);
	if (s->size == 0)
	{
		s->tail = NULL;
		s->head = NULL;
	}
	return (n);
}
