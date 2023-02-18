#ifndef PIPEX_H
# define PIPEX_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"../get_next_line/get_next_line.h"

//execute
void	free_all(char **str);
char	*is_accessed(char *cmd, char **path);
void	execute(char *argv, char **envp);

//parsing
char	**parsing_path(char **envp);

//ft_split
char	**ft_split(char const *s, char c);

//util
void	print_error(char *errmsg);
char	*ft_strcat(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

//pipex
void	open_infile(char **argv, int fd[2]);
void	close_pipe(int fd[2]);
void	created_first_process(int argc, char **argv, char **envp);

#endif
