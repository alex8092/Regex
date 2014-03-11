#include "ft_regex.h"
#include <unistd.h>

t_regex	*ft_regex(char *str)
{
	t_regbuilder	rb;

	rb.str = str;
	rb.pos = 0;
	rb.begin = NULL;
	rb.end = NULL;
	rb.escape = false;
	ft_regex_parse(&rb);
	return (rb.begin);
}
