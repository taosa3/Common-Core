/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:51:50 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 14:08:08 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char src[50] = "This is a test string for memcpy comparison.";
	char dest1[50];
	char dest2[50];
	size_t n = strlen(src) + 1;

	// Using standard memcpy for comparison
	memcpy(dest1, src, n);
	// Using ft_memcpy
	ft_memcpy(dest2, src, n);

	// Print the results
	printf("Source:   %s\n", src);
	printf("memcpy:   %s\n", dest1);
	printf("ft_memcpy:%s\n", dest2);

	// Check if both copies are the same
	if (strcmp(dest1, dest2) == 0)
	{
		printf("Test passed! ft_memcpy and memcpy give the same output.\n");
	}
	else
	{
		printf("Test failed! Outputs are different.\n");
	}

	// Additional test for overlapping regions (to check if 
	// your function handles it)
	char overlap_src[50] = "Overlap test for ft_memcpy.";
	ft_memcpy(overlap_src + 5, overlap_src, strlen(overlap_src) - 5);
	printf("Overlapping copy result: %s\n", overlap_src);

	return 0;
}
*/