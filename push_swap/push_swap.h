#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					n;
	int					index;
	int					push_cost;
	bool				above_medium;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//stack
void	init_stack(t_stack_node **stack, char **argv);

//checks
int		check_valid_numbers(char *argv);
int		check_duplicates(t_stack_node *stack);

//errors
void	free_stack(t_stack_node *stack);
void	error(t_stack_node *stack, char *msg);
#endif