/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:43:17 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/13 15:53:46 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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

static char	**free_thing(char **ans)
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
	ans[i] = NULL;
	return (ans);
}
