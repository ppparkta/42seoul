#include	"push_swap.h"

void	ft_push(t_stack *s, int data)
{
	t_node	*node;

	node=ft_calloc(1,sizeof(t_node));
	if(!node)
		ft_error(s);
	node->data = data;
	if (s->size==0)
	{
		s->head=node;
		s->tail=node;
	}
	else
	{
		s->head->prev=node;
		node->next=s->head;
		s->head=node;
	}
	s->size++;
}

int	ft_pop(t_stack *s)
{
	int		n;
	t_node	*tmp;

	n = s->head->data;
	s->size--;
	tmp=s->head;
	s->head=s->head->next;
	if(s->size==0)
		s->tail=NULL;
	free(tmp);
	return (n);
}
