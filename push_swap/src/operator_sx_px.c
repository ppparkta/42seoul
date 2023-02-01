/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_sx_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:48 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/31 17:11:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sx(t_stack *s, char *msg)
{
	t_node *tmp;

	if (s->size == 2)
	{
		s->head->next = NULL;
		s->head->prev = s->tail;
		s->tail->next = s->head;
		s->tail->prev = NULL;
		tmp = s->tail;
		s->tail = s->head;
		s->head = tmp;
	}
	else if (s->size > 2)
	{
		tmp = s->head->next;
		tmp->next->prev = s->head;
		s->head->next = tmp->next;
		s->head->prev = tmp;
		tmp->prev = NULL;
		tmp->next = s->head;
		s->head = tmp;
	}
	if (msg && s->size >= 2)
		ft_printf("%s/n", msg);
}

void ss(t_stack *a, t_stack *b, char *msg)
{
	sx(a, NULL);
	sx(b, NULL);
	if (msg)
		ft_printf("%s\n", msg);
}

void px(t_stack *from, t_stack *to, char *msg)
{
	int n;

	if (from->size == 0)
		return;
	n = ft_pop(from);
	ft_push(to, n);
	if (msg)
		ft_printf("%s\n", msg);
}
