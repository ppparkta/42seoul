/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:05:18 by hunpark           #+#    #+#             */
/*   Updated: 2023/02/21 17:25:10 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(const char *s);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
int		ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
