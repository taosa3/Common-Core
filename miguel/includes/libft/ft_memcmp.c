/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:20:20 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/02 13:07:24 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str1[] = "Hello, world!";
    const char str2[] = "Hello, Warld!";
    size_t n = 13;

    // Test ft_memcmp
    int result1 = ft_memcmp(str1, str2, n);
    printf("ft_memcmp: Comparing first %zu bytes of \"%s\" and \"%s\": %d\n", 
            n, str1, str2, result1);

    // Test standard memcmp for comparison
    int result2 = memcmp(str1, str2, n);
    printf("memcmp: Comparing first %zu bytes of \"%s\" and \"%s\": %d\n", 
            n, str1, str2, result2);

    // Additional test cases with different values of n
    n = 7;
    result1 = ft_memcmp(str1, str2, n);
    result2 = memcmp(str1, str2, n);
    printf("\nComparing first %zu bytes:\n", n);
    printf("ft_memcmp: %d\n", result1);
    printf("memcmp: %d\n", result2);

    n = 20; // Larger than the length of the strings
    result1 = ft_memcmp(str1, str2, n);
    result2 = memcmp(str1, str2, n);
    printf("\nComparing first %zu bytes:\n", n);
    printf("ft_memcmp: %d\n", result1);
    printf("memcmp: %d\n", result2);

    return 0;
}

*/