/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:56:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/22 16:06:20 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	wait_buff(int cnt, int here_doc)
{
	int	i;

	i = -1;
	if (here_doc == 1)
		i = 0;
	while (++i < cnt)
	{
		if (wait(0) == -1)
			print_error("wait error");
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	heredoc_switch;

	i = 3;
	heredoc_switch = 0;
	if (argc < 5)
		print_error("format error");
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		if (argc < 6)
			print_error("format error");
		i = 4;
		heredoc_switch = 1;
		created_here_doc(argc, argv, envp);
	}
	else
		created_first_process(argc, argv, envp);
	while (i < argc - 1)
		created_middle_process(argc, argv, envp, i++);
	created_last_process(argc, argv, envp, heredoc_switch);
	wait_buff(argc - 2, heredoc_switch);
	unlink("tmp");
	return (0);
}
