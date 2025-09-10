/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:28:40 by tafonso           #+#    #+#             */
/*   Updated: 2025/08/30 02:37:28 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_last(t_stack_node *stack)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->n > max_node->n)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static void	append_stack(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->n = n;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack(t_stack_node **stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!check_valid_numbers(argv[i]))
			error(*stack, "There are invalid characters.");
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error(*stack, "Number is too big for int");
		if (!check_duplicates((*stack), (int)n))
			error(*stack, "There is duplicates");
		append_stack(stack, (int)n);
		i++;
	}
}
