/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:44:27 by anmiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:51:05 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

/*

#include <stdio.h>
#include <strings.h>  // For standard bzero
#include "libft.h"    // For custom bzero

int main(void)
{
    char buffer1[20];
    char buffer2[20];

    // Initialize buffers with non-zero values
    for (int i = 0; i < 20; i++) {
        buffer1[i] = 'A';
        buffer2[i] = 'A';
    }

    // Use custom bzero to set buffer1 to zero
    ft_bzero(buffer1, 20);

    // Use standard bzero to set buffer2 to zero
    bzero(buffer2, 20);

    // Print the results to compare
    printf("Buffer1 after custom bzero: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", buffer1[i]);
    }
    printf("\n");

    printf("Buffer2 after standard bzero: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", buffer2[i]);
    }
    printf("\n");

    return 0;
}


*/