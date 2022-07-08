/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:21:00 by sooyang           #+#    #+#             */
/*   Updated: 2022/07/09 00:21:00 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
# define LIBFT_H

#include	<stdlib.h>
//#include	<unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *s);

#endif