#include "ft_regex.h"

char	*ft_regmatch(char *str, t_regex *regex, size_t *len_match)
{
	t_regmatch	rm;
	int			size;

	rm.str = str;
	rm.pos = 0;
	rm.begin = regex;
	if ((size = ft_matcher(&rm, rm.pos, rm.begin)))
	{
		*len_match = size;
		return (str + rm.pos);
	}
	return (NULL);
}
