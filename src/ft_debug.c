#include "ft_regex.h"

#if REGEX_DEBUG == 1
char	*ft_regop_to_str(t_regop op)
{
	if (op == REGOP_BASE)
		return ("Base");
	else if (op == REGOP_PIPE)
		return ("Pipe");
	else if (op == REGOP_BEG)
		return ("Begin");
	else if (op == REGOP_END)
		return ("End");
	else if (op == REGOP_BRACK)
		return ("Brack");
	else if (op == REGOP_REP)
		return ("Rep");
	else if (op == REGOP_SUB)
		return ("Sub");
	else if (op == REGOP_ANY)
		return ("Any");
	else
		return ("Unknow");
}
#endif
