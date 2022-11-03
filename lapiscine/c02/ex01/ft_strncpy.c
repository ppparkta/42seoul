/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:04:23 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:28:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
			dest[i] = src[i];
			i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include	<stdio.h>
#include	<string.h>

int	main(void)
{
	char src[]="i want to go home...";
	char dest[90];
	printf("ft_strncpy: %s\n", ft_strncpy(dest, src, 4));
	printf("strncpy: %s\n", strncpy(dest, src, 4));
}*/
