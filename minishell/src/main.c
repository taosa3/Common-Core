#include "minishell.h"

int main(int ac, char **av, char **env)
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
		free(input);
	}
}