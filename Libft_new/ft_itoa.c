/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:22:26 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/16 18:45:56 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	int_cnt(int n, size_t *sym)
{
	size_t	i;

	*sym = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		else
		{
			n = -n;
			*sym = 1;
		}
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + *sym);
}

static void	str_fill(char *ans, size_t len, int n)
{
	if (n == 0)
		ans[0] = '0';
	while (n)
	{
		ans[len - 1] = n % 10 + '0';
		n /= 10;
		len --;
	}
}

char	*ft_itoa(int n)
{
	size_t		len;
	size_t		sym;
	char		*ans;

	len = int_cnt(n, &sym);
	ans = malloc(sizeof(unsigned char) * len + 1);
	if (ans == 0)
		return (0);
	ans[len] = 0;
	if (n == -2147483648)
	{
		ans[10] = '8';
		ans[0] = '-';
		n = 214748364;
		len--;
	}
	else if (sym == 1)
	{
		ans[0] = '-';
		n = -n;
	}
	str_fill(ans, len, n);
	return (ans);
}
