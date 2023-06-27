/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:44:28 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/21 12:56:20 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<string.h>
//#include	<stdio.h>

int	is_length(char *str)
{
	int	leng;

	leng = 0;
	while (str[leng] != '\0')
		leng++;
	return (leng);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	a;

	len1 = is_length(s1);
	len2 = is_length(s2);
	if (len1 < n && len2 < n)
	{
		if (len1 <= len2)
			n = len2;
		else
			n = len1;
	}
	a = 0;
	while (a < n)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}

/*int	main(void)
{
	char *s1="abcdefgk";
	char *s2="abcdefg";
	int a;

	a=strncmp(s2,s1,8);
	printf("%d\n", a);

	a=ft_strncmp(s2,s1,8);
	printf("%d\n", a);

}*/
