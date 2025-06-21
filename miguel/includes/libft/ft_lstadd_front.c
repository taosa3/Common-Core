/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:06:08 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/09 12:10:40 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*

#include <stdio.h>

int main(void)
{
    // Create a few nodes to add to the list
    t_list *head = NULL;
    t_list *node1 = ft_lstnew("Second node");
    t_list *node2 = ft_lstnew("First node");

    // Add nodes to the front of the list
    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);

    // Print the list to verify the order of nodes
    t_list *current = head;
    while (current)
    {
        printf("Node content: %s\n", (char *)current->content);
        current = current->next;
    }

    // Free the allocated nodes
    free(node1);
    free(node2);

    return 0;
}

*/