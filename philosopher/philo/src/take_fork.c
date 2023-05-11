/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:30:27 by sooyang           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/10 00:39:45 by sooyang          ###   ########.fr       */
=======
/*   Updated: 2023/05/10 16:28:00 by sooyang          ###   ########.fr       */
>>>>>>> 031ae4e98ea3f39c7e435f1c43702864a6ded78a
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->all_fork[philo->left_fork]);
<<<<<<< HEAD
	if (check_dead(philo->table) == 0)
		print_msg(philo, " has taken a fork\n");
	pthread_mutex_lock(&philo->table->all_fork[philo->right_fork]);
	if (check_dead(philo->table) == 0)
		print_msg(philo, " has taken a fork\n");
=======
	// if (check_dead(philo->table))
	print_msg(philo, " has taken a fork\n");
	pthread_mutex_lock(&philo->table->all_fork[philo->right_fork]);
	// if (check_dead(philo->table))
	print_msg(philo, " has taken a fork\n");
>>>>>>> 031ae4e98ea3f39c7e435f1c43702864a6ded78a
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->all_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->all_fork[philo->right_fork]);
}
