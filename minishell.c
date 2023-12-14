#include "minishell.h"

int main()
{
    t_test  info;
    char    *res;

    while ((res = readline(stdin)) != 0)
    {
        printf("cmd = %s\n", buffer);
		write(1, "$> ", 3);
    }
}