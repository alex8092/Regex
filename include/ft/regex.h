#ifndef FT_REGEX_H
# define FT_REGEX_H
# define REGEX_DEBUG 0

# if REGEX_DEBUG == 1
#  include <stdio.h>
#  define DEBUG(X) printf X;
# else
#  define DEBUG(X)
# endif
# include <ft/common.h>

typedef struct s_regex		t_regex;
typedef enum e_regop		t_regop;

enum e_regop
{
	REGOP_BASE,
	REGOP_PIPE,
	REGOP_BEG,
	REGOP_END,
	REGOP_BRACK,
	REGOP_REP,
	REGOP_SUB,
	REGOP_ANY
};

struct		s_regex
{
	t_regop	type;
	t_bool	is_rep;
	t_regex	*prev;
	t_regex	*next;
};


# if REGEX_DEBUG == 1
char	*ft_regop_to_str(t_regop op);
# endif

t_regex		*ft_regex(char *str);
char		*ft_regmatch(char *str, t_regex *reg, size_t *len_match);
char		*ft_regmatch_replace(char *str, t_regex *reg, char *repl);
char		*ft_regmatch_replace_all(char *str, t_regex *reg, char *repl);

#endif
