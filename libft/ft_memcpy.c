/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:53:07 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 00:53:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	char	*pointer;
	size_t	i;

	if (dest == '\0' && src == '\0')
		return (0);
	pointer = (char *)dest;
	i = 0;
	while (i < n)
	{
		*pointer++ = *((char *)src++);
		i++;
	}
	return (dest);
}