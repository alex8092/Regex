#include "ft_regex.h"

t_opbase	*ft_create_opbase(t_regbuilder *rb)
{
	t_opbase	*reg;

	reg = (t_opbase*)ft_new_reg(rb->end, REGOP_BASE, sizeof(t_opbase));
	if (reg)
	{
		reg->c = rb->str[rb->pos];
		DEBUG(("\tData {c} : '%c'\n", reg->c));
		rb->end = (t_regex *)reg;
		++rb->pos;
	}
	return (reg);
}
