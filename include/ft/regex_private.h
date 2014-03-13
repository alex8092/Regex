#ifndef FT_REGEX_PRIVATE_H
# define FT_REGEX_PRIVATE_H

# include "regex.h"

typedef struct s_regbuilder	t_regbuilder;

typedef struct s_opbase		t_opbase;
typedef struct s_oppipe		t_oppipe;
typedef t_regex				t_opbeg;
typedef t_regex				t_opend;
typedef struct s_opbrack	t_opbrack;
typedef struct s_oprep		t_oprep;
typedef struct s_opsub		t_opsub;
typedef struct s_regmatch	t_regmatch;
typedef t_regex				t_opany;

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

t_regex		*ft_new_reg(t_regex *parent, t_regop type, int size);
t_opbase	*ft_create_opbase(t_regbuilder *rb);
t_oppipe	*ft_create_oppipe(t_regbuilder *rb);
t_opbrack	*ft_create_opbrack(t_regbuilder *rb);
t_oprep		*ft_create_oprep(t_regbuilder *rb);
t_opbeg		*ft_create_opbeg(t_regbuilder *rb);
t_opend		*ft_create_opend(t_regbuilder *rb);
t_opsub		*ft_create_opsub(t_regbuilder *rb);
t_opany		*ft_create_opany(t_regbuilder *rb);
void		ft_regex_parse(t_regbuilder *rb);
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
