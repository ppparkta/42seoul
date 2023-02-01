/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:31:59 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/18 18:19:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*new1;
	unsigned char	*new2;
	size_t			i;

	i = 0;
	new1 = (unsigned char *)s1;
	new2 = (unsigned char *)s2;
	while (n--)
	{
		if (new1[i] != new2[i] || new1[i] == 0 || new2[i] == 0)
			return (new1[i] - new2[i]);
		i++;
	}
	return (0);
}
