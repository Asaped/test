#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_token
{
    char    *word;
	char	op;
	struct s_token	*next;
}              t_token;

typedef	struct	s_list
{
	char	*command;
	t_token	*token;
}				t_list;

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include "gnl/get_next_line.h"

# endif
