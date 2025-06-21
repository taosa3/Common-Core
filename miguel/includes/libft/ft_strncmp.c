/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:29:59 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 14:02:15 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, Universe!";
    size_t n = 7;  // Number of characters to compare

    // Test ft_strncmp
    int result1 = ft_strncmp(str1, str2, n);
    printf("ft_strncmp: Comparing first %zu characters of \"%s\" 
		and \"%s\": %d\n", n, str1, str2, result1);

    // Test standard strncmp for comparison
    int result2 = strncmp(str1, str2, n);
    printf("strncmp: Comparing first %zu characters of \"%s\" and \"%s\": %d\n", 
            n, str1, str2, result2);

    // Additional test cases with different values of n
    n = 5;
    result1 = ft_strncmp(str1, str2, n);
    result2 = strncmp(str1, str2, n);
    printf("\nComparing first %zu characters:\n", n);
    printf("ft_strncmp: %d\n", result1);
    printf("strncmp: %d\n", result2);

    n = 20; // Larger than both strings
    result1 = ft_strncmp(str1, str2, n);
    result2 = strncmp(str1, str2, n);
    printf("\nComparing first %zu characters:\n", n);
    printf("ft_strncmp: %d\n", result1);
    printf("strncmp: %d\n", result2);

    return 0;
}

*/