#include "ft_regex.h"

int	ft_match_base(t_regmatch *rm, int pos, t_regex *cur)
{
	DEBUG(("Match [%s] { '", ft_regop_to_str(cur->type)));
	DEBUG(("%c' - '%c' (reg) }\n", rm->str[pos], ((t_opbase*)cur)->c));
	if (rm->str[pos] == ((t_opbase *)cur)->c)
		return (1);
	return (0);
}
