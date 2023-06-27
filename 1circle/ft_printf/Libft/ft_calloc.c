/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:50:25 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/13 21:23:41 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	maxel;

	maxel = (size_t)-1;
	if (count > maxel / size)
		return (0);
	ans = malloc(size * count);
	if (ans == 0)
		return (0);
	ft_bzero(ans, (size * count));
	return (ans);
}
