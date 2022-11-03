/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:55:45 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:34:38 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	is_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_str_is_numeric(char *str)
{
	int	a;
	int	len;

	len = is_length(str);
	if (len == 0)
		return (1);
	a = 0;
	while (a < len)
	{
		if (!(str[a] >= '0' && str[a] <= '9'))
			return (0);
		a++;
	}
	return (1);
}

/*
#include	<stdio.h>

int main(void)
{
	printf("숫자만 있을때: %d\n", ft_str_is_numeric("123"));
	printf("다른 문자 포함: %d\n", ft_str_is_numeric("ab123cDe"));
	printf("빈 문자열: %d\n", ft_str_is_numeric(""));
}*/
