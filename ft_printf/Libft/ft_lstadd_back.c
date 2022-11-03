/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:57:31 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/16 20:05:31 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	temp;

	temp = lst;
	if (*lst == 0 && new != 0)
	{
		*lst = new;
		return ;
	}
	else if(*lst == 0 && new == 0)
		return ;
	while (*lst -> next != 0)
	{
		*lst = *lst -> next;
	}
	*lst -> next = new;
	*lst = temp;
}
