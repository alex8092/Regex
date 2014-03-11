#include "ft_regex.h"

t_opsub	*ft_create_opsub(t_regbuilder *rb)
{
	t_opsub	*sub;

	sub = (t_opsub *)ft_new_reg(rb->end, REGOP_SUB, sizeof(t_opsub));
	if (sub)
	{
		if (rb->str[rb->pos] == '(')
			sub->type_sub = 0;
		else
			sub->type_sub = 1;
		DEBUG(("\tData {type_sub} : %d\n", sub->type_sub));
		++rb->pos;
		rb->end = (t_regex *)sub;
	}
	return (sub);
}
