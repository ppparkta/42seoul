/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:46:13 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/17 19:46:13 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*fnode;

	if (f == 0 || del == 0)
		return (0);
	new = 0;
	while (lst)
	{
			fnode = f(lst -> content);
			temp = ft_lstnew(fnode);
			if (temp == 0)
			{
				if (fnode != 0)
					free(fnode);
				ft_lstclaer(&new, del);
				return (0);
			}
			ft_lstadd_back(&new, temp);
			temp = temp -> next;
			lst = lst -> next;
	}
	return (new);
}