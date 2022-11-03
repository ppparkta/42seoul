/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:00:16 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:33:17 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	leng(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_str_is_alpha(char *str)
{
	int	a;
	int	len;

	len = leng(str);
	if (len == 0)
		return (1);
	a = 0;
	while (a < len)
	{
		if (!(str[a] >= 'a' && str[a] <= 'z'))
		{
			if (!(str[a] >= 'A' && str[a] <= 'Z'))
				return (0);
		}
		a++;
	}
	return (1);
}

/*
#include	<stdio.h>

int main(void)
{
	printf("알파벳만 있을때: %d\n", ft_str_is_alpha("abcDe"));
	printf("다른 문자 포함: %d\n", ft_str_is_alpha("ab123cDe"));
	printf("빈 문자열: %d\n", ft_str_is_alpha(""));
}*/
