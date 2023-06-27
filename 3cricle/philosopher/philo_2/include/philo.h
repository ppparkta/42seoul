/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/14 00:51:13 by sooyang          ###   ########.fr       */
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

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	long long		start_time;
	int				is_died;
	int				is_full;
	int				fork_list[1000];
	pthread_t		monitor_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_is_died;
	pthread_mutex_t	m_is_full;
	pthread_mutex_t	m_last_eaten;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				fork_right;
	int				fork_left;
	int				eat_count;
	long long		last_eaten;
	pthread_t		thread;
	t_info			*info;
}	t_philo;

//init
int			init_philo(t_philo **philo, t_info *info);
int			init_info(t_info *info);
int			set_info(t_info *info, char **argv);

//take_fork
void		pick_up_fork(t_info *info, t_philo *philo);
void		put_down_fork(t_info *info, t_philo *philo);

//philo_life_cycle
void		*one_philo(t_info *info, t_philo *philo);
void		change_die_flag(t_info *info);
void		set_last_eat(t_info *info, t_philo *philo);
void		set_full_philo(t_info *info);
void		run(t_philo *philo, t_info *info);

//monitoring
int			check_death(t_info *info);
int			check_end(t_info *info, t_philo *philo, int i);
void		*monitoring(void *philos);

//utils
int			ft_atoi(const char *s);
int			ft_usleep(int sleep_utime);
long long	init_time(void);
void		pass_time(t_philo *philo, int time);
void		print_philo(t_info *info, int id, int status);
void		destroy_mutex(t_info *info);

#endif
