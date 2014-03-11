#include "ft_regex.h"

int	ft_match_beg(t_regmatch *rm, int pos, t_regex *cur)
{
	(void)rm;
	(void)cur;
	DEBUG(("Match [Begin] : '%c'\n", rm->str[pos]));
	if (pos == 0)
		return (1);
	return (0);
}

int	ft_match_end(t_regmatch *rm, int pos, t_regex *cur)
{
	(void)rm;
	(void)pos;
	(void)cur;
	if (rm->str[pos] == 0)
		return (1);
	return (0);
}
