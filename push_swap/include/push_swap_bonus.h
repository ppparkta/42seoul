/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:40:11 by sooyang           #+#    #+#             */
/*   Updated: 2023/02/08 14:41:51 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

//ft_split
static size_t	word_cnt(char const *s, char c);
static char		*ft_strndup(const char *s, size_t n);
static char		**free_thing(char	**ans);
char			**ft_split(char const *s, char c);

//parsing
void			parsing(t_stack *stack, int i, char **arg);
void			check_idx(t_stack *stack, int tmp);
void			is_digit(char *arg);

//push_swap_util
int				ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);

//push_swap
void			wrong_format(void);

//sort
void			swap_a_to_b(t_stack *a, t_stack *b);
void			swap_a_to_b_chunk(t_stack *a, t_stack *b, int chunk, int n);
void			swap_b_to_a(t_stack *a, t_stack *b);
void			swap_b_to_a_chunk(t_stack *a, t_stack *b, int n);

//stack
t_stack			*stack_init(void);
void			init_node(t_stack *stack);
void			push(t_stack *s, int data, int index);
void			first_push(t_stack *s, int data, int index);
t_node			*pop(t_stack *s);

int				ft_strcmp(char *s1, char *s2);
void			checker(char *str, t_stack *a, t_stack *b);
void			check_sorted(t_stack *a, t_stack *b);

//operator
void			rrx(t_stack *s, char *msg);
void			rrr(t_stack *a, t_stack *b, char *msg);
void			rx(t_stack *s, char *msg);
void			rr(t_stack *a, t_stack *b, char *msg);
void			sx(t_stack *s, char *msg);
void			ss(t_stack *a, t_stack *b, char *msg);
//void			px(t_stack *from, t_stack *to, char *msg);

//checker
void			pa(t_stack *b, t_stack *a);
void			pb(t_stack *a, t_stack *b);

#endif
