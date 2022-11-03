/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:49:00 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/11 21:09:56 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;

	if (s1 == 0|| s2 == 0)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (ans == 0)
		return (0);
	i = 0;
	while (i < s1len)
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2len)
	{
		ans[i + j] = s2[j];
		j++;
	}
	ans[i + j] = 0;
	return (ans);
}
