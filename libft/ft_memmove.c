/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:09:19 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 15:58:01 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*cdest;
	const char		*csrc;
	size_t			i;

	cdest = dest;
	csrc = src;
	i = 0;
	if (cdest == 0 && csrc == 0)
		return (dest);
	if (cdest >= (char *)csrc)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (i < n)
		{
			*cdest-- = *((char *)csrc--);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*cdest++ = *((char *)csrc++);
			i++;
		}
	}
	return (dest);
}
