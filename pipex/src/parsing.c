/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:38:24 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/17 22:02:17 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parsing_path(t_pipe *info, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
	}
	if (envp[i] == NULL)
		print_error("env error");
	info->path = ft_split(envp[i] + 5, ':');
	return ;
}