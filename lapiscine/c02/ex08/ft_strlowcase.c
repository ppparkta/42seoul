/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:45:52 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:43:55 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	is_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strlowcase(char *str)
{
	int	a;
	int	len;

	len = is_length(str);
	a = 0;
	while (a < len)
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] += 32;
		a++;
	}
	return (str);
}

/*
#include	<stdio.h>

int main(void)
{
	char s1[]="ABCDP";
	printf("%s\n", ft_strlowcase(s1));
}*/
