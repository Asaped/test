#include "minishell.h"

static char	*set_operator(char *input)
{
	count_operator
}

static char	**parse_args(char *input)
{
	char	**res;

	res = malloc(sizeof(char *) * 2);
	if (!res)
		return (NULL);
	res[0] = set_word(input);
	res[1] = set_operator;
}

int main()
{
    t_list  info;
    char    *input;

	
	write(1, "$> ", 3);
    res = get_next_line(0);
    while (res)
    {
		info.token = parse_args(&info, input);
		free(input);
    	res = get_next_line(0);
    }
}
