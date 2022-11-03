/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:48:49 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/21 12:56:27 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<string.h>
//#include	<stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*i;

	i = dest;
	while (*i)
	{
		i++;
	}
	while (*src)
	{
		*i = *src;
		src++;
		i++;
	}
	*i = '\0';
	return (dest);
}

/*int	main(void)
{
	char s1[100];
	//strcat(s1,"defg");
	printf("%s\n",strcat(s1,"defg"));
	//s1=ft_strcat(s1,"zzz");
	printf("%s\n",ft_strcat(s1,"zzz"));
}*/
