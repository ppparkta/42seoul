/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:01:58 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 21:08:55 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1len;
	unsigned char	*s2len;

	s1len = (unsigned char *)s1;
	s2len = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1len[i] != s2len[i])
			return (s1len[i] - s2len[i]);
		i++;
	}
	return (0);
}
