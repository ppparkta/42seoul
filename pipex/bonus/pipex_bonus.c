/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:10:52 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/20 19:03:30 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	close_pipe(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	open_infile(char **argv, int fd[2])
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		print_error("open error");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		print_error("dup2 error (infile)");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 error (fd[1])");
	close(infile_fd);
	close_pipe(fd[0], fd[1]);
}

void	pipe_connected(int fd[2])
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 error");
	close_pipe(fd[1], fd[0]);
}

void	created_last_process(int argc, char **argv, char **envp)
{
	int		outfile_fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		print_error("fork error");
	else if (pid == 0)
	{
		outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
			print_error("open error");
		if (dup2(outfile_fd, 1) == -1)
			print_error("dup2 error");
		execute(argv[argc - 2], envp);
	}
	close_pipe(0, 1);
}

void	created_middle_process(int argc, char **argv, char **envp, int i)
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
		pipe_connected(fd);
		execute(argv[i], envp);
	}
	else if (pid > 0)
	{
		if (dup2(fd[0], 0) == -1)
			print_error("dup2 error (fd[0])");
		close_pipe(fd[0], fd[1]);
	}
}

void	created_first_process(int argc, char **argv, char **envp)
{
	int		wait;
	int		status;
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
		execute(argv[2], envp);
	}
	if (pid > 0)
	{
		if (dup2(fd[0], 0) == -1)
			print_error("dup2 error (fd[0])");
		close_pipe(fd[0], fd[1]);
	}
}
