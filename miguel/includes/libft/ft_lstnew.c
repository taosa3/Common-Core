/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:48:40 by anmiguel          #+#    #+#             */
/*   Updated: 2025/03/19 17:25:47 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content, int *index)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->number = content;
	new_node->index = ++(*index);
	new_node->cost = 0;
	new_node->below_median = false;
	new_node->cheapest = false;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/*

#include <stdio.h>

int main(void)
{
    // Define some content for the node
    char *content = "Hello, world!";
    
    // Create a new list node using ft_lstnew
    t_list *node = ft_lstnew(content);
    
    // Check if the node was created successfully
    if (node != NULL)
    {
        // Print the content of the new node
        printf("Node content: %s\n", (char *)node->content);
    }
    else
    {
        printf("Failed to create node.\n");
    }
    
    // Free the allocated memory
    free(node);
    
    return 0;
}

*/