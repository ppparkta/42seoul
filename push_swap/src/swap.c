/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:54:54 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/03 17:44:03 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int check_dir(t_stack *a, int n, int chunk)
{
	int count;
	int dir;
	t_node *cursor;

	count = 0;
	dir = 0;
	cursor = a->head;
	while (cursor->index > n + chunk)
	{
		cursor = cursor->next;
		count++;
	}
	if (count > (a->size - n) / 2)
		dir = 1;
	return (dir);
}

void swap_a_to_b_chunk(t_stack *a, t_stack *b, int chunk, int n)
{
	int dir;
	int size;

	size = a->size;
	while (n < size)
	{
		if (a->head->index < n)
		{
			px(a, b, "pb");
			n++;
		}
		else if (a->head->index >= n && a->head->index <= n + chunk)
		{
			px(a, b, "pb");
			rx(b, "rb");
			n++;
		}
		else if (a->head->index > n + chunk)
		{
			dir = check_dir(a, n, chunk);
			// if (dir == 0)
				rx(a, "ra");
			// else if (dir == 1)
			// 	rrx(a, "rra");
		}
	}
}

void swap_a_to_b(t_stack *a, t_stack *b)
{
	int chunk;

	chunk = (0.000000053 * a->size * a->size) + (0.03 * a->size) + 14.5;
	swap_a_to_b_chunk(a, b, chunk, 0);
}

void swap_b_to_a_chunk(t_stack *a, t_stack *b, int n)
{
	t_node *cursor;
	int cnt;

	while (n >= 0)
	{
		cursor = b->head;
		cnt = 0;
		while (cursor->index != n)
		{
			cnt++;
			cursor = cursor->next;
		}
		if (cnt <= (b->size / 2))
		{
			while (b->head->index != n)
			{
				rx(b, "rb");
			}
		}
		else if (cnt > (b->size / 2))
		{
			while (b->head->index != n)
			{
				rrx(b, "rrb");
			}
		}
		px(b, a, "pa");
		n--;
	}
}

void swap_b_to_a(t_stack *a, t_stack *b)
{
	t_node *cursor;
	int n;

	n = b->size - 1;
	swap_b_to_a_chunk(a, b, n);
}