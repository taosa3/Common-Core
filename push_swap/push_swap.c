#include "push_swap.h"

int	check_valid_numbers(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current	= stack;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->n == next->n)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	error(t_stack_node *stack, char *msg)
{
	free_stack(stack);
	ft_printf("Error: %s\n", msg);
	exit(1);
}