/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_sx_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:48 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/02 21:50:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sx(t_stack *s, char *msg)
{
	int tmp_i;
	int tmp_j;

	if (s->size >= 2)
	{
		tmp_i = s->head->data;
		s->head->data = s->head->next->data;
		s->head->next->data = tmp_i;
		tmp_j = s->head->index;
		s->head->index = s->head->next->index;
		s->head->next->index = tmp_j;
	}
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	ss(t_stack *a, t_stack *b, char *msg)
{
	sx(a, NULL);
	sx(b, NULL);
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	px(t_stack *from, t_stack *to, char *msg)
{
	t_node	*node;

	if (from->head != NULL)
	{
		node = pop(from);
		if (to->head == NULL)
		{
			node->prev = node;
			node->next = node;
			to->head = node;
			to->tail = node;
		}
		else
		{
			node->next = to->head;
			node->prev = to->tail;
			to->tail->next = node;
			to->head->prev = node;
			to->head = node;
		}
	}
	if (to->head == from->head)
		init_node(from);
	if (msg)
		ft_putstr_fd(msg, 1);
}
