/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:10:24 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/13 21:45:00 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

#include	<stdio.h>
#include	<string.h>


static size_t	int_cnt(long long n)
{
	size_t		i;
	
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	num;
	char		*ans;
	
	num = n;
	len = int_cnt(num);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (ans == 0)
		return (0);
	if (num < 0)
	{
		ans[0] = '-';
	}
	ans[len] = 0;
	while(num)
	{
		ans[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (ans);
}

#include	<stdio.h>
#include	<string.h>

int main()
{
//	int c = 25615684;

	for(int i=0;i<5;i++)
	{
		printf("%c\n", ft_itoa(-156)[i]);
	}
}
