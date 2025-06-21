/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:41:03 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 14:55:58 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/*

#include <stdio.h>

int main(void)
{
    // Test 1: Basic case where substring is within bounds
    char *str1 = "Hello, world!";
    char *sub1 = ft_substr(str1, 7, 5); // Expected: "world"
    printf("Test 1: Substring of \"%s\" from index 7 with 
	length 5: \"%s\"\n", str1, sub1);
    free(sub1);

    // Test 2: Start index is within bounds, len is greater 
	// than remaining characters
    char *str2 = "Hello, world!";
    char *sub2 = ft_substr(str2, 7, 50); // Expected: "world!"
    printf("Test 2: Substring of \"%s\" from index 7 with 
	length 50: \"%s\"\n", str2, sub2);
    free(sub2);

    // Test 3: Start index is beyond the length of the string
    char *str3 = "Hello, world!";
    char *sub3 = ft_substr(str3, 20, 5); // Expected: ""
    printf("Test 3: Substring of \"%s\" from index 20 with 
	length 5: \"%s\"\n", str3, sub3);
    free(sub3);

    // Test 4: Empty substring (len = 0)
    char *str4 = "Hello, world!";
    char *sub4 = ft_substr(str4, 5, 0); // Expected: ""
    printf("Test 4: Substring of \"%s\" from index 5 with 
	length 0: \"%s\"\n", str4, sub4);
    free(sub4);

    // Test 5: Start is 0, len is the length of the string
    char *str5 = "Hello, world!";
    char *sub5 = ft_substr(str5, 0, 13); // Expected: "Hello, world!"
    printf("Test 5: Substring of \"%s\" from index 0 with 
	length 13: \"%s\"\n", str5, sub5);
    free(sub5);

    // Test 6: Start is 0, len exceeds string length
    char *str6 = "Hello, world!";
    char *sub6 = ft_substr(str6, 0, 50); // Expected: "Hello, world!"
    printf("Test 6: Substring of \"%s\" from index 0 with 
	length 50: \"%s\"\n", str6, sub6);
    free(sub6);

    return 0;
}

*/