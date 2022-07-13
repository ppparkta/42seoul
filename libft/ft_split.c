/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:10:42 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/13 20:31:33 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
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

static char	*word_thing(char const *s1, char c, int *i)
{
	char	*ans;
	int 	i;


}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**ans;

	if (s == 0)
		return (0);
	ans = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (ans == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		
	}
	return (ans);
}*/
