/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:38:24 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/20 18:46:35 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	**parsing_path(char **envp)
{
	int		i;
	char	**path;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
	}
	if (envp[i] == NULL)
		return NULL;
	path = ft_split(envp[i] + 5, ':');
	return (path);
}