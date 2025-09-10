/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:29:32 by tafonso           #+#    #+#             */
/*   Updated: 2025/08/30 02:17:50 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av += 1;
	init_stack(&a, av);
	if (!check_sorted(a))
	{
		if (stack_len(a) == 2)
			sort_two(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
		{
			assign_indexes(a);
			radix_sort(&a, &b);
		}
	}
	free_all(a, b, ac, av);
}
