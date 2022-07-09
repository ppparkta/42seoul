/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:46:09 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 17:26:05 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sc;
	size_t			i;

	i = n;
	sc = (unsigned char *)s;
	while (i > 0)
	{
		*sc++ = 0;
		i--;
	}
}
