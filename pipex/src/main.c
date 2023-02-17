/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:56:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/17 23:56:40 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	info;
	int		stdin_dup;
	int		stdout_dup;

	stdin_dup = dup(0);
	stdout_dup = dup(1);
	if (argc != 5)
		print_error("format error");
	parsing_path(&info, envp);
	created_process_first(argc, argv, envp);
	//created_process_second();
	return (0);
}
