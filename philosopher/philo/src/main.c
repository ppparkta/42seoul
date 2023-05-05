/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:06 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/06 03:21:35 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv){
	t_philo	*philo;
	t_table	table;

	if (argc != 5 || argc != 6)
		return (0);
	if (init_table(&table, argc, argv) && init_philo(&philo, argc, argv))
	{
		//개쩌는 작업(미래의 나 파이팅)
		//필로가 살아 숨쉬는 함수
		philo_enter();
	}
	return (0);
}