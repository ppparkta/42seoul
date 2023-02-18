/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:58:55 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/18 17:25:44 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}


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

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*str;
//	int		i;
//	int		j;
//	int		s1_len;
//	int		s2_len;

//	i = 0;
//	j = 0;
//	if (s1 == 0 || s2 == 0)
//		return (NULL);
//	s1_len = ft_strlen(s1);
//	s1_len = ft_strlen(s1);
//	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
//	if (!str)
//		return (NULL);
//	while (i < s1_len)
//	{
//		str[i] = s1[i];
//		i++;
//	}
//	while (j < s2_len)
//		str[i++] = s2[j++];
//	str[i] = 0;
//	return (str);
//}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

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
