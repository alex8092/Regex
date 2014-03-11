#include "ft_regex.h"

void	ft_regex_parse(t_regbuilder *rb)
{
	while (rb->str[rb->pos])
	{
		if (!rb->escape)
		{
			if (rb->str[rb->pos] == '^' && rb->pos == 0)
				ft_create_opbeg(rb);
			else if (rb->str[rb->pos] == '$' && rb->str[rb->pos + 1] == 0)
				ft_create_opend(rb);
			else if (rb->str[rb->pos] == '|')
				ft_create_oppipe(rb);
			else if (rb->str[rb->pos] == '[')
				ft_create_opbrack(rb);
			else if (rb->str[rb->pos] == '{')
				ft_create_oprep(rb);
			else if (ft_isinarray(rb->str[rb->pos], "()"))
				ft_create_opsub(rb);
			else if (rb->str[rb->pos] == '.')
				ft_create_opany(rb);
			else if (rb->str[rb->pos] == '\\')
			{
				rb->escape = true;
				++rb->pos;
			}
			else
				ft_create_opbase(rb);
		}
		else
		{
			ft_create_opbase(rb);
			rb->escape = false;
		}
		if (!rb->begin)
			rb->begin = rb->end;
	}
}
