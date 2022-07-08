/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:28:13 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 00:28:13 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*memset(void *s, int c, size_t n)
{
	char	*sc;
	size_t	i;

	i = n;
	sc = (char *)s;
	while (i > 0)
	{
		*sc++ = (unsigned char)c;
		i--;
	}
	return (sc);
}