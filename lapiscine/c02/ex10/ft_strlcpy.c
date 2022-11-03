/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:59:32 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:50:42 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	while (src[length])
		length++;
	while (i < length && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (length);
}

/*
#include	<stdio.h>
#include	<string.h>

int main(void)
{
	char src[]="wlq...";
	char dest[10];
	printf("ft_strlcpy: %u, %s\n", ft_strlcpy(dest, src, 4), dest);
	printf("strlcpy: %lu, %s", strlcpy(dest, src, 4), dest);
}*/
