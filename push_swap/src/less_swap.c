/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:58:11 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/13 13:39:57 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_num(t_stack *a, t_stack *b, int n, int size)
{
	t_node	*cursor;
	int		count;

	while (size - n > 3)
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

void	sort_three(t_stack *s, int size)
{
	if (s->head->index == size - 3)
	{
		if (s->head->next->index == size - 1)
		{
			sx(s, "sa");
			rx(s, "ra");
		}
	}
	else if (s->head->index == size - 2)
	{
		if (s->head->next->index == size - 3)
			sx(s, "sa");
		else
			rrx(s, "rra");
	}
	else if (s->head->index == size - 1)
	{
		if (s->head->next->index == size - 3)
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
	int	size;

	size = a->size;
	if (size == 2 && a->head->index == 1)
		sx(a, "sa");
	if (size == 3)
		sort_three(a, size);
	if (size == 4)
	{
		find_num(a, b, 0, size);
		sort_three(a, size);
		px(a, b, "pa");
	}
	if (size == 5)
	{
		find_num(a, b, 0, size);
		sort_three(a, size);
		px(a, b, "pa");
		px(a, b, "pa");
	}
	exit(0);
}
