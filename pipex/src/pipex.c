/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:10:52 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/18 17:18:00 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void open_infile(char **argv, int fd[2])
{
	int infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		print_error("open error");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		print_error("dup2 error (infile)");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 error (fd[1])");
	close(infile_fd);
	close_pipe(fd);
	printf("succesful open\n");
}

void close_pipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void created_first_process(int argc, char **argv, char **envp)
{
	int	wait;
	int	status;
	int fd[2];
	pid_t pid;

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
		wait = waitpid(pid, &status, 0);
		if (dup2(fd[0], 0) == -1)
			print_error("dup2 error (fd[0])");
		close_pipe(fd);
		printf("succesful execve\n");
	}
}
