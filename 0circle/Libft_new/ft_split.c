/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:10:42 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/18 16:15:54 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	word_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = 0;
	if (n == 0)
		return (0);
	s1 = (char *)malloc(sizeof(char) * n + 1);
	if (s1 == 0)
		return (0);
	while (i < n)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

static char	**free_thing(char	**ans)
{
	size_t	i;

	i = 0;
	while (ans[i])
	{
		free(ans[i]);
		i++;
	}
	free(ans);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	temp;
	char	**ans;

	if (s == 0)
		return (0);
	ans = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (ans == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < word_cnt(s, c) && s[j] != 0)
	{
		while (s[j] == c)
			j++;
		temp = j;
		while (s[j] != c && s[j] != 0)
			j++;
		ans[i] = ft_strndup(&s[temp], j - temp);
		if (ans[i++] == 0)
			return (free_thing(ans));
	}
	ans[i] = 0;
	return (ans);
}
