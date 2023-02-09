/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:20:58 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/09 19:11:11 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
		if (arg[i] == 0)
			wrong_format();
	}
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			wrong_format();
		i++;
	}
}

void	check_idx(t_stack *stack, int tmp)
{
	t_node	*cursor;

	cursor = stack->head;
	while (cursor->next != stack->head)
	{
		if (cursor->data == tmp)
			wrong_format();
		else if (cursor->data < tmp)
			stack->tail->index++;
		else if (cursor->data > tmp)
			cursor->index++;
		cursor = cursor->next;
	}
}

void	parsing(t_stack *stack, int i, char **arg)
{
	int			j;
	long long	tmp;

	if (arg[0] == NULL)
		wrong_format();
	j = -1;
	while (arg[++j])
	{
		is_digit(arg[j]);
		tmp = ft_atoi(arg[j]);
		if (tmp < -2147483648 || tmp > 2147483647)
			wrong_format();
		first_push(stack, tmp, 0);
		check_idx(stack, tmp);
		free(arg[j]);
	}
}