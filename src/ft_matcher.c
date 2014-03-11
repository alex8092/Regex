#include "ft_regex.h"

static void	ft_match_next(t_regex **cur)
{
	if ((*cur)->type == REGOP_REP)
	{
		*cur = (*cur)->next;
		ft_match_next(cur);
	}
	else if ((*cur)->type == REGOP_SUB && ((t_opsub*)(*cur))->type_sub == 0)
	{
		*cur = (*cur)->next;
		while ((*cur)->type != REGOP_SUB)
		{
			*cur = (*cur)->next;
			DEBUG(("Match next [%s]\n", ft_regop_to_str((*cur)->type)));
		}
		ft_match_next(cur);
	}
	else
		*cur = (*cur)->next;
}

int	ft_match_dispatch(t_regmatch *rm, int pos, t_regex *cur)
{
	if (cur->type == REGOP_BASE)
		return (ft_match_base(rm, pos, cur));
	else if (cur->type == REGOP_BRACK)
		return (ft_match_brack(rm, pos, cur));
	else if (cur->type == REGOP_REP)
		return (ft_match_rep(rm, pos, cur));
	else if (cur->type == REGOP_ANY)
		return (ft_match_any(rm, pos, cur));
	else if (cur->type == REGOP_SUB)
		return (ft_match_sub(rm, pos, cur));
	else if (cur->type == REGOP_BEG)
		return (ft_match_beg(rm, pos, cur));
	else if (cur->type == REGOP_END)
		return (ft_match_end(rm, pos, cur));
	return (0);
}

int	ft_match(t_regmatch *rm, int pos, t_regex *cur)
{
	int	postmp;
	int	size;

	postmp = pos;
	size = 0;
	while (cur && rm->str[pos])
	{
		if (cur->type == REGOP_SUB && ((t_opsub*)cur)->type_sub == 1)
			break ;
		DEBUG(("ft_match(%s)\n", ft_regop_to_str(cur->type)));
		size = ft_match_dispatch(rm, postmp, cur);
		DEBUG(("\tft_match size : %d\n", size));
		if (!size && !(cur->type == REGOP_REP && ((t_oprep*)cur)->min == 0))
			return (0);
		if (cur->type != REGOP_BEG && cur->type != REGOP_END)
			postmp += size;
		ft_match_next(&cur);
	}
	return (postmp - pos);
}

int	ft_matcher(t_regmatch *rm, int pos, t_regex *cur)
{
	int	size;

	while (rm->str[pos])
	{
		if ((size = ft_match(rm, pos, cur)))
		{
			rm->pos = pos;
			return (size);
		}
		++pos;
	}
	return (0);
}
