/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:34:39 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 14:20:23 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *) s);
	return (NULL);
}

/*

#include <stdio.h>
#include <string.h> 

int main(void)
{
    const char *test_strings[] = {
        "Hello, world!",
        "This is a test string.",
        "Another test.",
        "Find the character.",
        "",
        NULL // End of strings
    };
    
    char test_chars[] = {'H', 't', 'z', 'x', ' ', '!', '\0'}; 
	// Characters to search

    printf("Testing ft_strchr against standard strchr:\n");
    printf("%-20s %-10s %-10s\n", "String", "ft_strchr", "strchr");
    
    for (int i = 0; test_strings[i] != NULL; i++)
    {
        for (int j = 0; test_chars[j] != '\0'; j++)
        {
            char *result_ft = ft_strchr(test_strings[i], test_chars[j]);
            char *result_std = strchr(test_strings[i], test_chars[j]);
            
            // Print results
            printf("%-20s %-10s %-10s\n", test_strings[i], 
                result_ft ? result_ft : "NULL", 
                result_std ? result_std : "NULL");
        }
    }

    return 0;
}

*/