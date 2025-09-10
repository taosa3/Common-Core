/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 02:31:56 by tafonso           #+#    #+#             */
/*   Updated: 2025/08/30 02:32:48 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack_node *a, t_stack_node *b, int ac, char **str)
{
	free_stack(a);
	free_stack(b);
	if (ac == 2)
		free_split(str);
	exit(0);
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	error(t_stack_node *stack, char *msg)
{
	free_stack(stack);
	ft_printf("Error: %s\n", msg);
	exit(1);
}
