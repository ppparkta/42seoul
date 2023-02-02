/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:54:54 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/02 21:02:47 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_dir(t_stack *a, int n,int chunk)
{
	int		count;
	int		dir;
	t_node	*cursor;

	count = 0;
	dir = 0;
	cursor = a->head;
	while (cursor->index > n + chunk)
	{

	}
}

void	swap_a_to_b_chunk(t_stack *a, t_stack *b, int chunk, int n)
{
	int	dir;

	while (a->head != NULL)
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
			if (dir == 0)
				rx(a, "ra");
			else
				rrx(a, "rra");
		}
	}
}

void	swap_a_to_b(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk;

	n = 0;
	chunk = (0.000000053 * a->size * a->size) + (0.03 * a->size) + 14.5;
	swap_a_chunk(a, b, chunk, n);
}

void	swap_a_to_b_chunk(t_stack *a, t_stack *b, int n)
{

}

void	swap_b_to_a(t_stack *a, t_stack *b)
{
	
}