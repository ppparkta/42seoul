/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:45:00 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/13 15:53:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	close_pipe(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	print_error(char *errmsg)
{
	write(2, errmsg, ft_strlen(errmsg));
	write(2, "\n", 1);
	exit(1);
}

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
