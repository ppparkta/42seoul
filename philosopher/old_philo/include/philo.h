/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 20:31:17 by sooyang          ###   ########.fr       */
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
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		time_to_die;
	long long		start_time;
	int				eat_count;
	int				is_dead;
	pthread_mutex_t	*all_fork;
	pthread_mutex_t	m_is_dead;
	pthread_mutex_t	print;
}	t_table;

typedef struct s_philo{
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	m_is_full;
	pthread_mutex_t	m_time_to_last_eaten;
	int				philo_num;
	int				eat_count;
	long long		time_to_last_eaten;
	int				is_full;
	t_table			*table;
}	t_philo;

//init
int			init_table(t_table *table, int argc, char **argv);
int			init_philo(t_table *table, t_philo **philo);
//monitoring
void		end_simulation(t_table *table, t_philo *philo);
void		monitoring(t_table *table, t_philo *philo);
//philo_enter
int			philo_enter(t_table *table, t_philo *philo);
int			check_dead(t_table *table);
//philo_behavior
void		print_msg(t_philo *philo, char *msg);
void		go_to_eat(t_philo *philo);
void		go_to_sleep(t_philo *philo);
//take_fork
void		pick_up_fork(t_philo *philo);
void		put_down_fork(t_philo *philo);
//set_time
void		set_time(t_table *table, t_philo *philo);
long long	get_time_table(long long check_time);
long long	get_time(void);
int			pass_time(long long time, t_philo *philo);
//utils
int			ft_atoi(const char *str);
#endif
