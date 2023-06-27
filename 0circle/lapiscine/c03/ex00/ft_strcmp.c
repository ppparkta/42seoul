/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:12:03 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/21 12:55:42 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<string.h>
//#include	<stdio.h>

int	is_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	len1;
	int	len2;
	int	a;

	a = 0;
	len1 = is_len(s1);
	len2 = is_len(s2);
	while (a < len2 || a < len1)
	{
		if (s1[a] > s2[a] || s1[a] < s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}

/*int	main(void)
{
	char *s1="abcde";
	char *s2="abcde";
	int a;

	a=strcmp(s2,s1);
	printf("%d\n",a);
	a=ft_strcmp(s2,s1);
	printf("%d\n",a);
}*/
