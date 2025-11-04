#include "minishell.h"

int	cd_builtin(char **av)
{
	char *home;
	
	if (!av[1])
	{
		home = getenv("HOME");
		if (!home)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("cd");
			return (1);
		}
		return (0);
	}
	if (chdir(av[1]) != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
