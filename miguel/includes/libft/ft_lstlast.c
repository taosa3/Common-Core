/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:18:56 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/09 12:28:23 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*

#include <stdio.h>

int main(void)
{
    // Create some nodes
    t_list *node1 = ft_lstnew("First node");
    t_list *node2 = ft_lstnew("Second node");
    t_list *node3 = ft_lstnew("Third node");

    // Link the nodes: node1 -> node2 -> node3
    node1->next = node2;
    node2->next = node3;

    // Use ft_lstlast to get the last node
    t_list *last_node = ft_lstlast(node1);

    // Print the content of the last node
    if (last_node)
        printf("Last node content: %s\n", (char *)last_node->content);
    else
        printf("The list is empty.\n");

    // Free the allocated nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

*/