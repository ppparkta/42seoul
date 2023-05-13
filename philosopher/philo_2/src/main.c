/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:05:26 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (1);
	if (set_info(&info, argv))
		return (1);
	if (init_info(&info) || init_philo(&philo, &info))
		return (1);
	run(philo, &info);
	destroy_mutex(&info);
	return (0);
}
