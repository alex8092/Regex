#include "ft_regex.h"

t_regex	*ft_new_reg(t_regex *parent, t_regop type, int size)
{
	t_regex	*regex;

	DEBUG(("Create regex[%s]\n", ft_regop_to_str(type)));
	regex = (t_regex *)ft_memalloc(size);
	if (regex)
	{
		regex->type = type;
		regex->prev = parent;
		if (parent)
			parent->next = regex;
	}
	return (regex);
}

