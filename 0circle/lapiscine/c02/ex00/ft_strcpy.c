/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:04:43 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:25:27 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include	<stdio.h>
#include	<string.h>

int	main(void)
{
	char src[]="i want to go home";
	char dest[90];
	printf("%s\n", src);
	printf("ft_strcpy: %s\n", ft_strcpy(dest, src));
	printf("strcpy: %s\n", strcpy(dest, src));
}*/
