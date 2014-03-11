#include "ft_regex.h"

int	ft_match_sub(t_regmatch *rm, int pos, t_regex *cur)
{
	int	size;

	if (cur->next && (size = ft_match(rm, pos, cur->next)))
		return (size);
	(void)size;
	(void)rm;
	(void)pos;
	(void)cur;
	return (1);
}
