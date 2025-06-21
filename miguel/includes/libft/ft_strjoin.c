/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:24:06 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/02 16:58:09 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*arr_str;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	arr_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!arr_str)
		return (NULL);
	i = 0;
	while (*s1)
		arr_str[i++] = *s1++;
	while (*s2)
		arr_str[i++] = *s2++;
	arr_str[i] = '\0';
	return (arr_str);
}

/*

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Test 1: Both strings are non-null
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *result1 = ft_strjoin(s1, s2);
    printf("Test 1: \"%s\"\n", result1); // Expected: "Hello, world!"
    free(result1); // Free the allocated memory

    // Test 2: First string is NULL
    char *result2 = ft_strjoin(NULL, s2);
    printf("Test 2: \"%s\"\n", result2); // Expected: "world!"
    free(result2); // Free the allocated memory

    // Test 3: Second string is NULL
    char *result3 = ft_strjoin(s1, NULL);
    printf("Test 3: \"%s\"\n", result3); // Expected: "Hello, "
    free(result3); // Free the allocated memory

    // Test 4: Both strings are NULL
    char *result4 = ft_strjoin(NULL, NULL);
    printf("Test 4: \"%s\"\n", result4 ? result4 : "NULL"); // Expected: NULL

    // Test 5: Empty strings
    char *result5 = ft_strjoin("", "");
    printf("Test 5: \"%s\"\n", result5); // Expected: ""
    free(result5); // Free the allocated memory

    // Test 6: One empty string
    char *result6 = ft_strjoin("", s2);
    printf("Test 6: \"%s\"\n", result6); // Expected: "world!"
    free(result6); // Free the allocated memory

    char *result7 = ft_strjoin(s1, "");
    printf("Test 7: \"%s\"\n", result7); // Expected: "Hello, "
    free(result7); // Free the allocated memory

    return 0;
}

*/