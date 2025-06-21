/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:38:26 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 14:16:26 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Helper function for backward copying
static void	*memmove_backward(unsigned char *d,
								const unsigned char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		((unsigned char *)d)[n] = ((unsigned char *)s)[n];
	}
	return (d);
}

// Helper function for forward copying
static void	*memmove_forward(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)d)[i] = ((unsigned char *)s)[i];
		i++;
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (d > s)
	{
		return (memmove_backward(d, s, n));
	}
	else
	{
		return (memmove_forward(d, s, n));
	}
}

/*

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    // Test case 1: Non-overlapping regions
    char src1[50] = "This is a test string for memmove comparison.";
    char dest1[50];
    char dest2[50];
    size_t n1 = strlen(src1) + 1;

    // Using standard memmove for comparison
    memmove(dest1, src1, n1);
    // Using ft_memmove
    ft_memmove(dest2, src1, n1);

    // Print the results
    printf("Non-overlapping test:\n");
    printf("Source:     %s\n", src1);
    printf("memmove:    %s\n", dest1);
    printf("ft_memmove: %s\n", dest2);

    // Check if both copies are the same
    if (strcmp(dest1, dest2) == 0)
    {
        printf("Non-overlapping test passed!\n");
    }
    else
    {
        printf("Non-overlapping test failed!\n");
    }

    // Test case 2: Overlapping regions (dest > src)
    char overlap_src[50] = "Overlap test for memmove.";
    printf("\nOverlapping test (dest > src):\n");
    memmove(overlap_src + 5, overlap_src, strlen(overlap_src) - 5);
    printf("memmove result:    %s\n", overlap_src);

    // Reset and test with ft_memmove
    strcpy(overlap_src, "Overlap test for memmove.");
    ft_memmove(overlap_src + 5, overlap_src, strlen(overlap_src) - 5);
    printf("ft_memmove result: %s\n", overlap_src);

    // Test case 3: Overlapping regions (src > dest)
    char overlap_dest[50] = "Another overlap test case for memmove.";
    printf("\nOverlapping test (src > dest):\n");
    memmove(overlap_dest, overlap_dest + 8, strlen(overlap_dest) - 8);
    printf("memmove result:    %s\n", overlap_dest);

    // Reset and test with ft_memmove
    strcpy(overlap_dest, "Another overlap test case for memmove.");
    ft_memmove(overlap_dest, overlap_dest + 8, strlen(overlap_dest) - 8);
    printf("ft_memmove result: %s\n", overlap_dest);

    return 0;
}

*/