/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:36:15 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 22:46:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	length(char *str)
{
	int	lengths;

	lengths = 0;
	while (str[lengths] != '\0')
		lengths++;
	return (lengths);
}

int	flag_zero(int flag, char *str, int a)
{
	if (flag == 0)
	{
		if (str[a] >= 'a' && str[a] <= 'z')
			str[a] -= 32;
		flag = 1;
	}
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	int	flag;
	int	l;
	int	a;

	flag = 1;
	l = length(str);
	a = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (a < l)
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] += 32;
		if (!(str[a - 1] >= 'A' && str[a - 1] <= 'Z'))
			if (!(str[a - 1] >= 'a' && str[a - 1] <= 'z'))
				if (!(str[a - 1] >= '0' && str[a - 1] <= '9'))
					flag = 0;
		flag = flag_zero(flag, str, a);
		a++;
	}
	return (str);
}

/*
#include	<stdio.h>

int main(void)
{
	char s1[]="salut, coMment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(s1));
}*/
