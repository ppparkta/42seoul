/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 19:28:39 by sooyang          ###   ########.fr       */
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
	int				is_full;
	int				is_dead;
	pthread_mutex_t	*all_fork;
	pthread_mutex_t	*m_time_to_last_eaten;
	pthread_mutex_t	m_is_full;
	pthread_mutex_t	m_is_dead;
	pthread_mutex_t	print;
}	t_table;

typedef struct s_philo{
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	int				philo_num;
	int				eat_count;
	long long		time_to_last_eaten;
	t_table			*table;
}	t_philo;

//init
int			init(t_philo **philo, t_table *table, int argc, char **argv);
int			init_mutex(t_table *table);

//philo
void		*philo_life_cycle(void *data);

//monitoring
void		*monitoring(void *data);
//utils
int			print_act(t_philo *philo, char *msg);
int			ft_atoi(const char *str);
//time
long long	get_time(void);
long long	get_time_table(long long check_time);
void		pass_time(t_philo *philo, long long time);
//error
int			print_error_message(char *message);
void		destroy_mutex(t_table *table);
int			mutex_error(t_philo *philo, char *message);
int			error_all(t_philo *philo, char *message);
#endif
