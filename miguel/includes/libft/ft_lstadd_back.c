/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:06:59 by anmiguel          #+#    #+#             */
/*   Updated: 2025/03/08 15:08:58 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list **last, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		(*last)->next = new;
		new->prev = *last;
	}
	*last = new;
}

/*

#include <stdio.h>

int main(void)
{
    // Create some nodes
    t_list *node1 = ft_lstnew("First node");
    t_list *node2 = ft_lstnew("Second node");
    t_list *node3 = ft_lstnew("Third node");
    
    // Initially, create a list with just node1
    t_list *head = node1;

    // Add node2 and node3 to the back of the list
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);

    // Print the entire list to verify the nodes were added correctly
    t_list *current = head;
    while (current)
    {
        printf("Node content: %s\n", (char *)current->content);
        current = current->next;
    }

    // Free the allocated nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

*/