/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/08 15:22:49 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv){
	t_philo	*philo;
	t_table	table;

	if (argc < 5 || argc > 6)
		return (1);
	if (init_table(&table, argc, argv) == 0 && init_philo(&table, &philo) == 0)
	{
		//필로 루틴
		philo_enter(&table, philo);
		//필로 사망 후?
		while(1);
	}
	return (0);
}