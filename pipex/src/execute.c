/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:52:36 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/19 22:11:17 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_all(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*is_accessed(char *cmd, char **path)
{
	int		i;
	char	*end_route_of_cmd;
	char	*all_route_of_cmd;

	i = 0;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	end_route_of_cmd = ft_strjoin("/", cmd);
	i = -1;
	while (path[++i])
	{
		all_route_of_cmd = ft_strjoin(path[i], end_route_of_cmd);
		if (access(all_route_of_cmd, X_OK) != -1)
		{
			free(end_route_of_cmd);
			return (all_route_of_cmd);
		}
		free(all_route_of_cmd);
	}
	free(end_route_of_cmd);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	*all_route_of_cmd;
	char	**path;
	char	**cmd_and_arg;

	path = parsing_path(envp);
	cmd_and_arg = ft_split(argv, ' ');
	all_route_of_cmd = is_accessed(cmd_and_arg[0], path);
	if (!all_route_of_cmd)
	{
		free_all(path);
		free_all(cmd_and_arg);
		print_error("command not found");
	}
	if (execve(all_route_of_cmd, cmd_and_arg, envp) == -1)
		print_error("execve error");
}