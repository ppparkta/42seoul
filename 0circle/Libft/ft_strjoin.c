/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:49:00 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/18 17:28:05 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	ans = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ans == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		ans[i + j] = s2[j];
		j++;
	}
	ans[i + j] = 0;
	return (ans);
}
