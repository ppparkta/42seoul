/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:22:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/20 19:47:23 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>

//here_doc
void	created_here_doc(int argc, char **argv, char **envp);

//execute
void	free_all(char **str);
char	*is_accessed(char *cmd, char **path);
void	execute(char *argv, char **envp);

//parsing
char	**parsing_path(char **envp);

//ft_split
char	**ft_split(char const *s, char c);

//util
void	close_pipe(int fd1, int fd2);
void	print_error(char *errmsg);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//pipex
void	open_infile(char **argv, int fd[2]);
void	pipe_connected(int fd[2]);
void	created_last_process(int argc, char **argv, char **envp, int heredoc);
void	created_middle_process(int argc, char **argv, char **envp, int i);
void	created_first_process(int argc, char **argv, char **envp);

#endif
