/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/07 02:57:40 by sooyang          ###   ########.fr       */
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
		//개쩌는 작업(미래의 나 파이팅)
		//필로가 살아 숨쉬는 함수
		philo_enter(&table, philo);
	}
	return (0);
}