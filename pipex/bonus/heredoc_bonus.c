/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:18:32 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/13 15:56:58 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	heredoc_pipe_connected(int infile_fd, int fd[2])
{
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		print_error("dup2 error (infile2)");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 error (fd[STDOUT])");
	close(infile_fd);
	close_pipe(fd[0], fd[1]);
}

void	check_temp(void)
{
	if (access("/tmp/.tmp", F_OK) == 0)
		print_error("open error");
	tmp_fd = open("/tmp/.tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (tmp_fd == -1)
		print_error("open error");
}

void	get_heredoc(char **argv, int fd[2])
{
	int		swc;
	int		tmp_fd;
	char	*buff;

	swc = 1;
	check_temp();
	while (swc)
	{
		write(1, "heredoc> ", 9);
		buff = get_next_line(STDIN_FILENO);
		if (buff == NULL)
			print_error("gnl error");
		if (ft_strncmp(argv[2], buff, ft_strlen(argv[2])) == 0)
		{	
			free(buff);
			swc = 0;
		}
		else
		{
			write(tmp_fd, buff, ft_strlen2(buff));
			free(buff);
		}
	}
	close(tmp_fd);
}

void	created_here_doc(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile_fd;
	pid_t	pid;

	get_heredoc(argv, fd);
	infile_fd = open("/tmp/.tmp", O_RDONLY);
	if (infile_fd == -1)
		print_error("open error");
	if (pipe(fd) == -1)
		print_error("pipe error");
	pid = fork();
	if (pid == -1)
		print_error("fork error");
	if (pid == 0)
	{
		heredoc_pipe_connected(infile_fd, fd);
		execute(argv[3], envp);
	}
	if (pid > 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			print_error("dup2 error (fd[STDIN])");
		close(infile_fd);
		close_pipe(fd[0], fd[1]);
	}
}
