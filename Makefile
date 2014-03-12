CC = gcc

COMMONDIR = Common
FTDIR = $(HOME)/.ft

CFLAGS = -Wall -Werror -Wextra -I$(INCLUDEDIR) -fPIC
CFLAGS += -I$(FTDIR)/include

DEBUG = true
ifeq ($(DEBUG), true)
	CFLAGS += -ggdb3
else
	CFLAGS += -O3
endif

LDFLAGS = -shared -L$(FTDIR)/lib -lcommon -Wl,-rpath,$(FTDIR)/lib

LD_LIBRARY_PATH=$(FTDIR)/lib:$(LD_LIBRARY_PATH)

NAME = $(LIBDIR)/$(SHORTNAME)
SHORTNAME = libregex.so

SRCS =	ft_create_opany.c \
		ft_create_opbase.c \
		ft_create_opbegend.c \
		ft_create_opbrack.c \
		ft_create_oppipe.c \
		ft_create_oprep.c \
		ft_create_opsub.c \
		ft_create_regex.c \
		ft_debug.c \
		ft_match_any.c \
		ft_match_base.c \
		ft_match_begend.c \
		ft_match_brack.c \
		ft_match_rep.c \
		ft_match_sub.c \
		ft_matcher.c \
		ft_regex.c \
		ft_regex_parse.c \
		ft_regmatch.c \
		ft_regmatch_replace.c

LIBDIR = lib
OBJDIR = obj
SRCDIR = src
INCLUDEDIR = include/ft

RED = \033[0;31m
GREEN = \033[0;32m
NO = \033[0m

OBJS_BASE = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJS_BASE))

all: $(NAME) print_error

print_begin:
	@rm -f .make_errors
	@echo "Compiling ..."

print_error:
	@if [ -e .make_errors ]; then cat .make_errors; fi
	@rm -f .make_errors

lib_common:
	echo "Compiling Common ..."
	@make -C $(COMMONDIR)
	echo "Installing Common ..."
	@make -C $(COMMONDIR) install

$(NAME): lib_common print_begin $(OBJS) print_error
	@mkdir -p $(LIBDIR)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

install:
	@make -C $(COMMONDIR) install
	@chmod +x install.sh
	@./install.sh $(NAME) $(INCLUDEDIR) $(LIBDIR)

uninstall:
	@make -C $(COMMONDIR) uninstall
	@chmod +x install.sh
	@./install.sh $(NAME) $(INCLUDEDIR) $(LIBDIR) uninstall

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors\
	  && echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

clean:
	@echo "Clean objects ..."
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Clean library ..."
	@rm -rf $(LIBDIR)


re: fclean all

.PHONY: all clean fclean re
