#include "minishell.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	error_exit(const char *err_message)
{
	printf("Error: ");
	printf("%s\n", err_message);
	exit(1);
}

static int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

static void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Malloc error.");
	return (ret);
}

/*static char	*set_operator(char *input)
{
	count_operator 
}
*/
static char	**parse_args(t_list *info, char *input)
{
	info.token =
	if (!res)
		return (NULL);
	res[0] = set_word(input);
	res[1] = set_operator;
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1 && src[i] && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	return (ft_strlen(src));
}

static int	is_command(char *str)
{
	if (!ft_memcmp(str, "echo", ft_strlen(str)))
		return (1);
	else if (!ft_memcmp(str, "pwd", ft_strlen(str)))
		return (1);
	else if (!ft_memcmp(str, "cd", ft_strlen(str)))
		return (1);
	else if (!ft_memcmp(str, "export", ft_strlen(str)))
		return (1);
	else if (!ft_memcmp(str, "unset", ft_strlen(str)))
		return (1);
	else if (!ft_memcmp(str, "env", ft_strlen(str)))
		return (1);
	else if (!ft_memcmp(str, "exit", ft_strlen(str)))
		return (1);
	return (0);
}

static char	*set_command(char *input)
{
	char	*str;
	int		len;

	len = 0;
	while (input[len] && input[len] != ' ')
		len++;
	if (!input[len + 1])
		error_exit("Missing argument.");
	printf("len = %i\n", len);
	str = safe_malloc(sizeof(char) * (len + 1));
	ft_strlcpy(str, input, len + 1);
	if (!is_command(str))
		error_exit("Command not found.");
	while (*input && *input != ' ')
		input++;
	return (str);
}

int main()
{
    t_list  info;
    char    *input;

	
	write(1, "$> ", 3);
    input = get_next_line(0);
    while (input)
    {
		info.command = set_command(input);
		info.token = parse_args(&info, input);
		free(input);
    	input = get_next_line(0);
    }
}
