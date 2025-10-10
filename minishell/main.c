#include "minishell.h"

int main()
{
	char *input;
	char **tokens;
	int i;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
			add_history(input);
		tokens = parse(input);
		i = 0;
		while (tokens[i])
		{
			printf("%s\n", tokens[i]);
			i++;
		}
		free(input);
		i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
}