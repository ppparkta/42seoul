/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:03:24 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/08 14:42:01 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			i++;
		else
			break;
	}
	return (s1[i] - s2[i]);
}

void	check_sorted(t_stack *a, t_stack *b)
{
	t_node	*cursor;

	if (b->size != 0)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	cursor = a->head;
	while (cursor != a->tail)
	{
		if (cursor->index > cursor->next->index)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		cursor = cursor->next;
	}
	write(1, "OK\n", 3);
	exit(0);
}

void checker(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "ra\n"))
		rx(a, NULL);
	else if (!ft_strcmp(str, "rb\n"))
		rx(b, NULL);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b, NULL);
	else if (!ft_strcmp(str, "rra\n"))
		rrx(a, NULL);
	else if (!ft_strcmp(str, "rrb\n"))
		rrx(b, NULL);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b, NULL);
	else if (!ft_strcmp(str, "sa\n"))
		sx(a, NULL);
	else if (!ft_strcmp(str, "sb\n"))
		sx(b, NULL);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, NULL);
	else if (!ft_strcmp(str, "pa\n"))
		pa(b, a);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b);
	else
		ft_putstr_fd("Error\n", 1);
}