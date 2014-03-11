#ifndef FT_REGEX_H
# define FT_REGEX_H
# define REGEX_DEBUG 0

# if REGEX_DEBUG == 1
#  include <stdio.h>
#  define DEBUG(X) printf X;
# else
#  define DEBUG(X)
# endif
# include "common.h"

typedef struct s_regex		t_regex;
typedef struct s_regbuilder	t_regbuilder;
typedef enum e_regop		t_regop;
typedef struct s_opbase		t_opbase;
typedef struct s_oppipe		t_oppipe;
typedef t_regex				t_opbeg;
typedef t_regex				t_opend;
typedef struct s_opbrack	t_opbrack;
typedef struct s_oprep		t_oprep;
typedef struct s_opsub		t_opsub;
typedef struct s_regmatch	t_regmatch;
typedef t_regex				t_opany;

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

struct		s_opbase
{
	t_regex	base;

	char	c;
};

struct		s_oppipe
{
	t_regex	base;

	int		type_pipe;
};

struct		s_opbrack
{
	t_regex	base;

	char	*str;
};

struct		s_oprep
{
	t_regex	base;

	int		min;
	int		max;
};

struct		s_opsub
{
	t_regex	base;

	int		type_sub;
};

struct		s_regbuilder
{
	char	*str;
	int		pos;
	t_bool	escape;
	t_regex	*begin;
	t_regex	*end;
};

struct		s_regmatch
{
	char	*str;
	int		pos;
	t_regex	*begin;
};

# if REGEX_DEBUG == 1
char	*ft_regop_to_str(t_regop op);
# endif

t_regex		*ft_new_reg(t_regex *parent, t_regop type, int size);
t_opbase	*ft_create_opbase(t_regbuilder *rb);
t_oppipe	*ft_create_oppipe(t_regbuilder *rb);
t_opbrack	*ft_create_opbrack(t_regbuilder *rb);
t_oprep		*ft_create_oprep(t_regbuilder *rb);
t_opbeg		*ft_create_opbeg(t_regbuilder *rb);
t_opend		*ft_create_opend(t_regbuilder *rb);
t_opsub		*ft_create_opsub(t_regbuilder *rb);
t_opany		*ft_create_opany(t_regbuilder *rb);
t_regex		*ft_regex(char *str);
void		ft_regex_parse(t_regbuilder *rb);
char		*ft_regmatch(char *str, t_regex *reg, size_t *len_match);
char		*ft_regmatch_replace(char *str, t_regex *reg, char *repl);
char		*ft_regmatch_replace_all(char *str, t_regex *reg, char *repl);
int			ft_matcher(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_dispatch(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_base(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_brack(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_rep(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_any(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_sub(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_beg(t_regmatch *rm, int pos, t_regex *cur);
int			ft_match_end(t_regmatch *rm, int pos, t_regex *cur);

#endif
