/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 02:37:49 by tafonso           #+#    #+#             */
/*   Updated: 2025/10/13 19:14:58 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//stack
void			init_stack(t_stack_node **stack, char **argv, int flag);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//checks
int				check_valid_numbers(char *argv);
int				check_duplicates(t_stack_node *stack, int n);
int				check_sorted(t_stack_node *stack);

//errors
void			free_all(t_stack_node *a, t_stack_node *b, char **str, \
int flag);
void			free_split(char **split);
void			free_stack(t_stack_node *stack);
void			error(t_stack_node *stack, char *msg, char **split, int flag);

//moves
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//sorting
void			sort_two(t_stack_node **a);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			assign_indexes(t_stack_node *stack);
void			radix_sort(t_stack_node **a, t_stack_node **b);
void			sort(t_stack_node **a, t_stack_node **b);

#endif