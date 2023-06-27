/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rrx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:56 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/13 13:33:26 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	rrx(t_stack *s, char *msg)
{
	if (s->size >= 2)
	{
		s->head = s->tail;
		s->tail = s->tail->prev;
	}
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	rrr(t_stack *a, t_stack *b, char *msg)
{
	rrx(a, NULL);
	rrx(b, NULL);
	if (msg)
		ft_putstr_fd(msg, 1);
}
