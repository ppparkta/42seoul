/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:44:13 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/21 12:56:48 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<string.h>
//#include	<stdio.h>

int	len(char *str)
{
	int	leng;

	leng = 0;
	while (str[leng] != '\0')
		leng++;
	return (leng);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{	
		if (*str == *to_find)
		{
			i = 0;
			while (*(str + i) == *(to_find + i))
			{
				i++;
				if (i == len(to_find))
					return (str);
			}
		}
		str++;
	}
	return (NULL);
}
