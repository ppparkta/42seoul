/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:22:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/13 16:02:00 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>

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
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

//pipex
void	open_infile(char **argv, int fd[2]);
void	close_pipe(int fd1, int fd2);
void	created_second_process(int argc, char **argv, char **envp);
void	created_first_process(int argc, char **argv, char **envp);

#endif
