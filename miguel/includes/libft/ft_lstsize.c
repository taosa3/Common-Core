/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:12:07 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/09 12:21:28 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*

#include <stdio.h>

int main(void)
{
    // Create individual nodes for the list
    t_list *node1 = ft_lstnew("First node");
    t_list *node2 = ft_lstnew("Second node");
    t_list *node3 = ft_lstnew("Third node");

    // Link nodes to form the list: node1 -> node2 -> node3
    node1->next = node2;
    node2->next = node3;

    // Use ft_lstsize to get the number of nodes in the list
    int size = ft_lstsize(node1);
    printf("List size: %d\n", size);

    // Expected output: "List size: 3"

    // Free the allocated nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

*/