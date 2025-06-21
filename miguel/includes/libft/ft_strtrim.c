/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:59:53 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 16:11:58 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_present(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr_str;
	size_t	i;
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	begin = 0;
	while (s1[begin] && ft_char_present(s1[begin], set))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_char_present(s1[end - 1], set))
		end--;
	arr_str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!arr_str)
		return (NULL);
	i = 0;
	while (begin < end)
		arr_str[i++] = s1[begin++];
	arr_str[i] = '\0';
	return (arr_str);
}

/*

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s1;
    char *set;
    char *result;

    // Test 1: Basic trimming of spaces from both ends
    s1 = "   Hello, World!   ";
    set = " ";
    result = ft_strtrim(s1, set);
    printf("Trimmed string (Test 1): \"%s\"\n", result); 
	// Expected: "Hello, World!"
    free(result);

    // Test 2: Trimming characters from both ends
    s1 = "xxHello, World!yy";
    set = "xy";
    result = ft_strtrim(s1, set);
    printf("Trimmed string (Test 2): \"%s\"\n", result); 
	// Expected: "Hello, World!"
    free(result);

    // Test 3: No trimming needed
    s1 = "Hello, World!";
    set = "xyz";
    result = ft_strtrim(s1, set);
    printf("Trimmed string (Test 3): \"%s\"\n", result); 
	// Expected: "Hello, World!"
    free(result);

    // Test 4: Trimming all characters
    s1 = "aaaaa";
    set = "a";
    result = ft_strtrim(s1, set);
    printf("Trimmed string (Test 4): \"%s\"\n", result); // Expected: ""
    free(result);

    // Test 5: Empty string input
    s1 = "";
    set = " ";
    result = ft_strtrim(s1, set);
    printf("Trimmed string (Test 5): \"%s\"\n", result); // Expected: ""
    free(result);

    // Test 6: Empty set input (no trimming should happen)
    s1 = "   Hello, World!   ";
    set = "";
    result = ft_strtrim(s1, set);
    printf("Trimmed string (Test 6): \"%s\"\n", result); 
	// Expected: "   Hello, World!   "
    free(result);

    // Test 7: NULL as input for s1 (edge case)
    s1 = NULL;
    set = " ";
    result = ft_strtrim(s1, set);
    if (!result)
        printf("Trimmed string (Test 7): NULL (as expected)\n");

    return 0;
}

*/