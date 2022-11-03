#include	"push_swap.h"

void	rrx(t_stack *s, char *msg)
{
	t_node	*tmp;

	if(s->size==2)
	{
		sx(s, NULL);
	}
	else if(s->size > 2)
	{
		tmp = s->tail->prev;
		tmp->next = NULL;
		s->tail->prev = NULL;
		s->tail->next = s->head;
		s->head->prev = s->tail;
		s->head = s->tail;
		s->tail = tmp;
	}
	if (msg && s->size >= 2)
		ft_printf("%s\n", msg);
}

void rrr(t_stack *a, t_stack *b, char *msg)
{
	rrx(a, NULL);
	rrx(b, NULL);
	if (msg)
		ft_printf("%s\n", msg);
}