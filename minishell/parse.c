#include "minishell.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static int	is_especial(char c)
{
	return (c == '|' || c == '>' || c == '<');
}

static	int is_quotes(char c)
{
	return (c == '\"' || c == '\'');
}

char	**parse(char *input)
{
	char	**tokens;
	int		i;
	int		j;
	int		start;
	char	quote;

	tokens = malloc(1024 * sizeof(char *));
	i = 0;
	j = 0;
	while (input[i])
	{
		while (is_space(input[i]))
			i++;
		if (!input[i])
			break ;
		if (is_especial(input[i]))
		{
			tokens[j] = malloc(2);
			tokens[j][0] = input[i];
			tokens[j][1] = '\0';
			j++;
			i++;
			continue ;
		}
		if (is_quotes(input[i]))
		{
			quote = input[i++];
			start = i;
			while (input[i] && input[i] != quote)
				i++;
			tokens[j] = ft_strndup(&input[start], (i + 1) - start);
			j++;
			if (input[i])
				i++;
			continue ;
		}
		else
		{
			start = i;
			while (input[i] && !is_space(input[i]) && !is_especial(input[i]))
				i++;
			tokens[j] = ft_strndup(&input[start], i - start);
			j++;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}