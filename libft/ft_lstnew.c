/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:28:28 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/16 19:35:18 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	ans = (t_list *)malloc(sizeof(t_list));
	if (ans == 0)
		return (0);
	ans -> content = content;
	ans -> next = 0;
	return (ans);
}
