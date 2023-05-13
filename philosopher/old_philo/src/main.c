/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 06:15:43 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{	
	t_philo	*philo;
	t_table	table;

	if (argc < 5 || argc > 6)
		return (1);
	if (init_table(&table, argc, argv))
		return (1);
	if (init_philo(&table, &philo) == 0)
	{
		philo_enter(&table, philo);
		monitoring(&table, philo);
	}
	end_simulation(&table, philo);
	free(table.all_fork);
	free(philo);
	return (0);
}
