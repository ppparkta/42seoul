/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:07:34 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/21 12:56:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdio.h>
//#include	<string.h>

int	le(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d;
	unsigned int	s;

	d = le(dest);
	s = le(src);
	if (size <= d)
		return (s + size);
	i = 0;
	while (i < size - 1 - d && src[i])
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = 0;
	return (d + s);
}
