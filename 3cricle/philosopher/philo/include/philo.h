/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:57:14 by sooyang           #+#    #+#             */
/*   Updated: 2023/05/13 22:05:49 by sooyang          ###   ########.fr       */
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
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				eat_count;
	long long		start_time;
	int				error;
	int				is_full;
	int				is_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*m_last_eaten;
	pthread_mutex_t	m_is_full;
	pthread_mutex_t	m_is_dead;
	pthread_mutex_t	print;
}	t_table;

typedef struct s_philo{
	pthread_t		thread;
	int				philo_num;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_eaten;
	t_table			*table;
}	t_philo;

//init
int		init_mutex(t_table *table);
int		init(t_philo **philo, t_table *table, int argc, char **argv);

//philo
void	*philo_life_cycle(void *data);
void	waiting(t_table *table, int time);

//monitoring
void	*monitoring(void *data);

//utils
int		print_log(t_philo *philo, char *message);
long	get_time(void);
int		ft_atoi(const char *str, t_table *table);

//error
int		print_error_message(char *message);
void	destroy_mutex(t_table *table);
int		mutex_error(t_table *table, char *message);
int		error(t_philo *philo, char *message);

#endif
