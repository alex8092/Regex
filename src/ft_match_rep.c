#include "ft_regex.h"

int	ft_match_rep(t_regmatch *rm, int pos, t_regex *cur)
{
	int		postmp;
	int		size;
	int		recur;
	t_oprep	*rep;
	t_regex	*next;

	postmp = pos;
	size = 0;
	rep = (t_oprep*)cur;
	recur = 0;
	DEBUG(("Match [%s]\n", ft_regop_to_str(cur->type)));
	cur = cur->next;
	next = cur->next;
	if (cur->type == REGOP_SUB && ((t_opsub*)cur)->type_sub == 0)
	{
		while (next->type != REGOP_SUB && ((t_opsub*)next)->type_sub == 1)
			next = next->next;
		next = next->next;
	}
	while (rm->str[postmp])
	{
		if (rep->max != 0 && recur == rep->max)
			break ;
		if (rep->min == 0 && next
			&& (size = ft_match(rm, postmp, next)))
			break ;
		size = ft_match_dispatch(rm, postmp, cur);
		if (!size)
			break ;
		postmp += size;
		if (next && (size = ft_match(rm, postmp, next)))
			break ;
		++recur;
	}
	DEBUG(("Match end [Rep] : recur[%d]\n", recur));
	return (postmp - pos);
}
