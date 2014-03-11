#include "ft_regex.h"

t_opany	*ft_create_opany(t_regbuilder *rb)
{
	t_opany	*any;

	any = ft_new_reg(rb->end, REGOP_ANY, sizeof(t_opany));
	if (any)
	{
		++rb->pos;
		rb->end = (t_regex *)any;
	}
	return (any);
}
