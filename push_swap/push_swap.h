#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}	t_stack

#endif
