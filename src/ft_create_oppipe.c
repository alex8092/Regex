#include "ft_regex.h"

t_oppipe	*ft_create_oppipe(t_regbuilder *rb)
{
	t_oppipe	*pipe;

	pipe = (t_oppipe *)ft_new_reg(rb->end, REGOP_PIPE, sizeof(t_oppipe));
	if (pipe)
	{
		pipe->type_pipe = 0;
		++rb->pos;
		rb->end = (t_regex *)pipe;
	}
	return (pipe);
}
