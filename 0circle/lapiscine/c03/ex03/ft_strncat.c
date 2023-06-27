/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:02:29 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/23 14:38:42 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdio.h>
//#include	<string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	char			*d;

	d = dest;
	j = 0;
	while (*d)
	{
		d++;
		j++;
	}
	i = 0;
	while (i < nb && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = 0;
	return (dest);
}

/*int	main(void)
{
	char s1[100]="abc";

	ft_strncat(s1, "def", 1);
	printf("%s\n", s1);
	strncat(s1, "ghi", 2);
	printf("%s\n", s1);
}*/
