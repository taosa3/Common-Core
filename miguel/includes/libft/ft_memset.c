/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:16:29 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 16:09:48 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_tmp;

	str_tmp = s;
	i = 0;
	while (i < n)
	{
		str_tmp[i] = c;
		i++;
	}
	return (s);
}

/*

#include <stdio.h>
#include <string.h>  // For standard memset
#include "libft.h"   // For custom ft_memset

int main(void)
{
    char buffer1[20];
    char buffer2[20];

    // Fill both buffers with 'X' characters using ft_memset and memset
    ft_memset(buffer1, 'X', sizeof(buffer1) - 1);
    buffer1[19] = '\0';  // Null-terminate the string for printing

    memset(buffer2, 'X', sizeof(buffer2) - 1);
    buffer2[19] = '\0';  // Null-terminate the string for printing

    // Print the results to compare
    printf("Buffer1 after ft_memset: %s\n", buffer1);
    printf("Buffer2 after memset:   %s\n", buffer2);

    // Test with zeroing out the buffers
    ft_memset(buffer1, 0, sizeof(buffer1));
    memset(buffer2, 0, sizeof(buffer2));

    printf("\nBuffer1 after zeroing with ft_memset: ");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", buffer1[i]);
    }
    printf("\n");

    printf("Buffer2 after zeroing with memset:   ");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", buffer2[i]);
    }
    printf("\n");

    return 0;
}

*/