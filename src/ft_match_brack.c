#include "ft_regex.h"

int	ft_match_brack(t_regmatch *rm, int pos, t_regex *cur)
{
	t_opbrack	*bk;

	bk = (t_opbrack*)cur;
	DEBUG(("Match [%s] { '", ft_regop_to_str(cur->type)));
	DEBUG(("%c' - \"%s\" (reg) }\n", rm->str[pos], bk->str));
	if (bk->str[0] != '^' && ft_isinarray(rm->str[pos], bk->str))
		return (1);
	else if (!ft_isinarray(rm->str[pos], bk->str + 1))
		return (1);
	return (0);
}
