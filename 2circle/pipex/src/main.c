/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:56:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/03/13 16:02:13 by sooyang          ###   ########.fr       */
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
	if (argc != 5)
		print_error("format error");
	created_first_process(argc, argv, envp);
	created_second_process(argc, argv, envp);
	wait_buff(argc - 3);
	return (0);
}
