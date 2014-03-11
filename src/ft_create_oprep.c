#include "ft_regex.h"

static void	ft_do_rep(t_regbuilder *rb, t_oprep *rep)
{
	t_regex	*cur;
	t_regex	*prev;

	cur = rb->end;
	if (cur->type == REGOP_SUB)
	{
		cur = cur->prev;
		while (cur->type != REGOP_SUB)
			cur = cur->prev;
	}
	prev = cur->prev;
	if (prev)
		prev->next = (t_regex *)rep;
	rep->base.next = cur;
	rep->base.prev = prev;
	cur->prev = (t_regex *)rep;
	if (!rep->base.prev)
		rb->begin = (t_regex *)rep;
}

t_oprep	*ft_create_oprep(t_regbuilder *rb)
{
	t_oprep	*rep;

	rep = (t_oprep*)ft_new_reg(NULL, REGOP_REP, sizeof(t_oprep));
	if (rep)
	{
		++rb->pos;
		rep->min = ft_atoi(rb->str + rb->pos);
		while (rb->str[rb->pos] != ',' && rb->str[rb->pos] != '}')
			++rb->pos;
		if (rb->str[rb->pos] == ',')
		{
			++rb->pos;
			rep->max = ft_atoi(rb->str + rb->pos);
			while (rb->str[rb->pos] != '}')
				++rb->pos;
		}
		else
			rep->max = -1;
		DEBUG(("\tData {min - max} : %d - %d\n", rep->min, rep->max));
		++rb->pos;
		ft_do_rep(rb, rep);
	}
	return (rep);
}
