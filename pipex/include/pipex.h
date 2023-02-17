#ifndef PIPEX_H
# define PIPEX_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"../get_next_line/get_next_line.h"

typedef struct s_pipe
{
	int		infile_fd;
	int		outfile_fd;
	int		fd[2];
	char	**path;
	char	*cmds;
}	t_pipe;

//parsing
void	parsing_path(t_pipe *info, char **envp);

//ft_split
char	**ft_split(char const *s, char c);

//util
void	ft_putstr_fd(char *s, int fd);

//pipex
void	print_error(char *errmsg);
void	open_infile(char **argv, int fd[2]);
void	close_pipe(int fd[2]);
void	created_process_first(int argc, char **argv, char **envp);

#endif
