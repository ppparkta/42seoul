/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:53:07 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 20:01:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointer;
	size_t			i;

	if (dest == 0 && src == 0)
		return (dest);
	pointer = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*pointer++ = *((unsigned char *)src++);
		i++;
	}
	return (dest);
}
