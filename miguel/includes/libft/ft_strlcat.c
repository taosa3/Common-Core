/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:13:43 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/01 18:05:39 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size == 0)
		return (src_len);
	else if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*

#include <stdio.h>
#include <string.h>

int main() {
    char dest1[20] = "Hello, ";
    char src1[] = "World!";
    size_t size1 = sizeof(dest1); // Proper size for this test

    char dest2[10] = "Hi, ";
    char src2[] = "there";
    size_t size2 = 10;

    char dest3[15] = "Test";
    char src3[] = " String";
    size_t size3 = 0; // Edge case where size is 0

    char dest4[5] = "abcd";
    char src4[] = "efg";
    size_t size4 = 4; // Edge case to test exact buffer limit

    char dest5[15] = "";
    char src5[] = "Hello";
    size_t size5 = 15; // Adequate size for the test

    // Test Case 1
    printf("Test Case 1:\n");
    size_t result1 = ft_strlcat(dest1, src1, size1);
    printf("Resulting string (ft_strlcat): \"%s\"\n", dest1);
    printf("Length attempted to create (ft_strlcat): %zu\n\n", result1);

    // Test Case 2
    printf("Test Case 2:\n");
    size_t result2 = ft_strlcat(dest2, src2, size2);
    printf("Resulting string (ft_strlcat): \"%s\"\n", dest2);
    printf("Length attempted to create (ft_strlcat): %zu\n\n", result2);

    // Test Case 3
    printf("Test Case 3:\n");
    size_t result3 = ft_strlcat(dest3, src3, size3);
    printf("Resulting string (ft_strlcat): \"%s\"\n", dest3);
    printf("Length attempted to create (ft_strlcat): %zu\n\n", result3);

    // Test Case 4
    printf("Test Case 4:\n");
    size_t result4 = ft_strlcat(dest4, src4, size4);
    printf("Resulting string (ft_strlcat): \"%s\"\n", dest4);
    printf("Length attempted to create (ft_strlcat): %zu\n\n", result4);

    // Test Case 5
    printf("Test Case 5:\n");
    size_t result5 = ft_strlcat(dest5, src5, size5);
    printf("Resulting string (ft_strlcat): \"%s\"\n", dest5);
    printf("Length attempted to create (ft_strlcat): %zu\n\n", result5);

    return 0;
}

*/