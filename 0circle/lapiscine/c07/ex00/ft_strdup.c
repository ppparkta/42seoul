/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:49:24 by sooyang           #+#    #+#             */
/*   Updated: 2022/05/03 19:47:06 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (src[len])
		len++;
	if ((char *)malloc(sizeof(char) * len) == 0)
		return (0);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dup))
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <string.h>
#include <stdio.h>

int main(void){
    char *path;

    path = ft_strdup("sooyang");
    printf("%s\n", path);
	free(path);
	return (0);
}*/
