/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:56:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/20 19:00:43 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	wait_buff(int cnt)
{
	int	i;

	i = -1;
	while (++i < cnt)
	{
		if (wait(0) == -1)
			print_error("wait error");
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	if (argc < 5)
		print_error("format error");
	//if (ft_strncmp("here_doc", argv[1], 8) == 0)
	//	created_here_doc();
	created_first_process(argc, argv, envp);
	i = 2;
	while (++i < argc - 1)
	{
		created_middle_process(argc, argv, envp, i);
	}
	created_last_process(argc, argv, envp);
	wait_buff(argc - 3);
	return (0);
}
