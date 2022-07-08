/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:10:58 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 02:10:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	length = 0;
	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[length])
		length++;
	while (i < length && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (length);
}