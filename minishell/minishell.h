#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_cmd
{
	char			**av; // av[0] == cmd, av[n++] == args
	char			*infile; //nome de ficheiro para '<' ou NULL
	char			*outfile; //nome de ficheiro para '>>', '>' ou NULL
	char			*heredoc; //string do heredoc ou fd ainda nao sei bem
	int				append; //1 se '>>', 0 se '>'
	int				pipe_to_next; //1 se tiver pipe para proximo comando
	struct s_cmd	*next;
}				t_cmd;

char	**parse(char *input);

#endif