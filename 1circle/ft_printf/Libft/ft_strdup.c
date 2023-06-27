/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:51:40 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/13 16:55:44 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ans;

	len = ft_strlen(s1);
	ans = (char *)(malloc)(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}
