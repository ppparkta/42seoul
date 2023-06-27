/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:54 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/03 17:19:44 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/push_swap.h"

void	rx(t_stack *s, char *msg)
{
	if (s->size >= 2)
	{
		s->tail = s->head;
		s->head = s->tail->next;
	}
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	rr(t_stack *a, t_stack *b, char *msg)
{
	rx(a, NULL);
	rx(b, NULL);
	if (msg)
		ft_putstr_fd(msg, 1);
}
