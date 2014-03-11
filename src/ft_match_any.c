#include "ft_regex.h"

int	ft_match_any(t_regmatch *rm, int pos, t_regex *cur)
{
	(void)rm;
	(void)pos;
	(void)cur;
	DEBUG(("Match [Any] : '%c'\n", rm->str[pos]));
	if (rm->str[pos])
		return (1);
	return (0);
}
