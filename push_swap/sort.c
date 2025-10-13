/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:13:58 by tafonso           #+#    #+#             */
/*   Updated: 2025/10/13 19:15:17 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack_node *a)
{
	int				min;
	int				position;
	int				i;
	t_stack_node	*stack;

	min = a->n;
	position = 0;
	stack = a;
	i = 0;
	while (stack)
	{
		if (stack->n < min)
		{
			min = stack->n;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

static void	push_min_to_b(t_stack_node **a, t_stack_node **b)
{
	int	position;
	int	size;

	position = find_min_position(*a);
	size = stack_len(*a);
	if (position <= size / 2)
		while (position-- > 0)
			ra(a);
	else
		while (position++ < size)
			rra(a);
	pb(a, b);
}

void	sort_two(t_stack_node **a)
{
	if (a && (*a)->n > (*a)->next->n)
		sa(a);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->n > (*a)->next->n)
		sa(a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	sort_two(a);
}
