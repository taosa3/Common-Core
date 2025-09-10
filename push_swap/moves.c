/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 02:18:57 by tafonso           #+#    #+#             */
/*   Updated: 2025/08/30 02:25:04 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	int	tmp;

	tmp = (*a)->n;
	(*a)->n = (*a)->next->n;
	(*a)->next->n = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	int	tmp;

	tmp = (*b)->n;
	(*b)->n = (*b)->next->n;
	(*b)->next->n = tmp;
	ft_printf("sb\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	temp->prev = NULL;
	*b = temp;
	ft_printf("pb\n");
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	temp->prev = NULL;
	*a = temp;
	ft_printf("pa\n");
}

void	ra(t_stack_node **a)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	ft_printf("ra\n");
}
