/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:56:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/19 22:45:48 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		created_here_doc();
	created_first_process(argc, argv, envp);
	i = -1;
	while (++i < argc - 3)
	{
		created_middle_process(argc, argv, envp);
	}
	created_second_process(argc, argv, envp);
	close_pipe(0, 1);
	wait_buff(argc - 3);
	return (0);
}
