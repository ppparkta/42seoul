/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:42:12 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:42:54 by sooyang          ###   ########.fr       */
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

char	*ft_strupcase(char *str)
{
	int	a;
	int	len;

	len = is_length(str);
	a = 0;
	while (a < len)
	{
		if (str[a] >= 'a' && str[a] <= 'z')
			str[a] -= 32;
		a++;
	}
	return (str);
}

/*
#include	<stdio.h>

int main(void)
{
	char s1[]="abcde";
	printf("%s\n", ft_strupcase(s1));
}*/
