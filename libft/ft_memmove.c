/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:09:19 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 17:27:57 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*cdest;
	const unsigned char		*csrc;
	size_t					i;

	cdest = dest;
	csrc = src;
	i = 0;
	if (cdest == 0 && csrc == 0)
		return (dest);
	if (cdest >= (unsigned char *)csrc)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (i < n)
		{
			*cdest-- = *((unsigned char *)csrc--);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*cdest++ = *((unsigned char *)csrc++);
			i++;
		}
	}
	return (dest);
}
