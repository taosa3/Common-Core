/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 02:23:54 by tafonso           #+#    #+#             */
/*   Updated: 2025/08/30 02:24:41 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack_node **b)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack_node **a)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	last = *a;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	last = *b;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a);
	rrb(b);
}
