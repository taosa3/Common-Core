/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:25:42 by tafonso           #+#    #+#             */
/*   Updated: 2025/08/30 01:28:20 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_stack_to_array(t_stack_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->n;
		stack = stack->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int value, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indexes(t_stack_node *stack)
{
	int				size;
	int				*arr;
	t_stack_node	*node;

	size = stack_len(stack);
	arr = copy_stack_to_array(stack, size);
	node = stack;
	sort_array(arr, size);
	while (node)
	{
		node->index = find_index(node->n, arr, size);
		node = node->next;
	}
	free(arr);
}
