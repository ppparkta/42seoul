/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:59:51 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:39:15 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	leg(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_str_is_printable(char *str)
{
	int	i;
	int	len;

	len = leg(str);
	if (len == 0)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

/*
#include	<stdio.h>

int main(void)
{
	printf("출력가능 문자만 있을때: %d\n", ft_str_is_printable("abcDe"));
	printf("다른 문자 포함: %d\n", ft_str_is_printable("ab12\nad"));
	printf("빈 문자열: %d\n", ft_str_is_printable(""));
}*/
