/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:22:56 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/16 19:09:02 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*ans;

	len = (unsigned int)ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (ans == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[len] = 0;
	return (ans);
}
