/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:09:22 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/26 20:44:29 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<stdio.h>

typedef struct s_fd
{
	int	fd[2];
	int	prev_fd[2];
}	t_fd;

#endif