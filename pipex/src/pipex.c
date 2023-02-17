/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:10:52 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/18 00:37:33 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void print_error(char *errmsg)
{
	perror(errmsg);
	exit(1);
}

void	open_infile(char **argv, int fd[2])
{
	int		infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		print_error("open error");
	if (dup2(infile_fd, 0) == -1)
		print_error("dup2 error");
	if (dup2(fd[1], 1) == -1)
		print_error("dup2 error");
	close(infile_fd);
	close_pipe(fd);
}

void	close_pipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void	created_process_first(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		print_error("pipe error");
	pid = fork();
	if (pid == -1)
		print_error("fork error");
	if (pid == 0)
	{
		open_infile(argv, fd);
		execute();
	}
}
