/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:58:11 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/08 15:58:17 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_num(t_stack *a, t_stack *b, int n)
{
	t_node	*cursor;
	int		count;

	while (a->size - n > 3)
	{
		cursor = a->head;
		count = 0;
		while (cursor->index != n)
		{
			cursor = cursor->next;
			count++;
		}
		if (count <= (a->size - n) / 2)
		{
			while (a->head->index != n)
				rx(a, "ra");
		}
		else if (count > (a->size - n) / 2)
		{
			while (a->head->index != n)
				rrx(a, "rra");
		}
		px(a, b, "pb");
		n++;
	}
}

void	sort_three(t_stack *s)
{
	if (s->head->index == s->size - 3)
	{
		if (s->head->next->index == s->size - 1)
		{
			sx(s, "sa");
			rx(s, "ra");
		}
	}
	else if (s->head->index == s->size - 2)
	{
		if (s->head->next->index == s->size - 3)
			sx(s, "sa");
		else
			rrx(s, "rra");
	}
	else if (s->head->index == s->size - 1)
	{
		if (s->head->next->index == s->size - 3)
			rx(s, "ra");
		else
		{
			sx(s, "sa");
			rrx(s, "rra");
		}
	}
}

void	less_swap(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->head->index == 1)
		sx(a, "sa");
	if (a->size == 3)
		sort_three(a);
	if (a->size == 4)
	{
		find_num(a, b, 0);
		sort_three(a);
		px(a, b, "pa");
	}
	if (a->size == 5)
	{
		find_num(a, b, 0);
		sort_three(a);
		px(a, b, "pa");
		px(a, b, "pa");
	}
	exit(0);
}