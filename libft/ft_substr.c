/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:14:08 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/13 17:01:30 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ans;

	i = 0;
	j = ft_strlen(s);
	if (j < start)
		return (ft_strdup(""));
	if (s == 0)
		return (0);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	while (i < len && s[start])
		ans[i++] = s[start++];
	ans[i] = 0;
	return (ans);
}
