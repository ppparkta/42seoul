/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/07 00:48:49 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_table{
	int				philo_head;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eat_count;
	int				start_time;
	int				is_dead;
	pthread_mutex_t	*all_fork;
	pthread_mutex_t	m_is_dead;
	pthread_mutex_t	print;
}	t_table;

typedef struct s_philo{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	m_p_is_dead;
	int				philo_num;
	int				eat_count;
	int				time_to_last_eaten;
	int				p_is_dead;
	t_table			*table;
}	t_philo;

//init
int	init_table(t_table *table, int argc, char **argv);
int init_philo(t_table *table, t_philo **philo);
//philo_enter
int		philo_enter(t_table *table, t_philo *philo);
//philo_behavior
void	go_to_eat(t_philo *philo);
void	go_to_sleep(t_philo *philo);
void	go_to_think(t_philo *philo);
//take_fork
void pick_up_fork(t_philo *philo);
void put_down_fork(t_philo *philo);
//set_time
void	set_time(t_table *table, t_philo *philo);
int		get_time_table(int check_time);
int		get_time(void);
//utils
int ft_atoi(const char *str);
#endif
