/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:28:40 by tafonso           #+#    #+#             */
/*   Updated: 2025/10/10 18:10:18 by tafonso          ###   ########.fr       */
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

void	sort(t_stack_node **a, t_stack_node **b)
{
	if (!check_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sort_two(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else if (stack_len(*a) == 5)
			sort_five(a, b);
		else
		{
			assign_indexes(*a);
			radix_sort(a, b);
		}
	}
}

void	init_stack(t_stack_node **stack, char **argv, int flag)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!check_valid_numbers(argv[i]))
			error(*stack, "There are invalid characters.", argv, flag);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error(*stack, "Number is too big for int", argv, flag);
		if (!check_duplicates((*stack), (int)n))
			error(*stack, "There is duplicates", argv, flag);
		append_stack(stack, (int)n);
		i++;
	}
}
