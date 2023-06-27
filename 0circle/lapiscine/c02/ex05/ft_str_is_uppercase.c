/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:07:37 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:37:12 by sooyang          ###   ########.fr       */
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

int	ft_str_is_uppercase(char *str)
{
	int	a;
	int	len;

	len = is_length(str);
	if (len == 0)
		return (1);
	a = 0;
	while (a < len)
	{
		if (!(str[a] >= 'A' && str[a] <= 'Z'))
			return (0);
		a++;
	}
	return (1);
}

/*
#include	<stdio.h>

int main(void)
{
	printf("대문자만 있을때: %d\n", ft_str_is_uppercase("ABCEFA"));
	printf("다른 문자 포함: %d\n", ft_str_is_uppercase("aAAb123cDe"));
	printf("빈 문자열: %d\n", ft_str_is_uppercase(""));
}*/
