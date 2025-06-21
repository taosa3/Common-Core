/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:29:21 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/02 15:36:30 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc(sizeof(*dup) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *test_strings[] = {
        "Hello, world!",
        "42 is amazing.",
        "",
        "This is a much longer string to test how ft_strdup 
		performs on larger inputs.",
        "Short"
    };
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (int i = 0; i < num_tests; i++) {
        const char *original = test_strings[i];

        // Duplicate string using ft_strdup and strdup
        char *ft_dup = ft_strdup(original);
        char *std_dup = strdup(original);

        // Print results
        printf("Test %d:\n", i + 1);
        printf("   Original: \"%s\"\n", original);
        printf("   ft_strdup: \"%s\"\n", ft_dup ? ft_dup : "NULL");
        printf("   strdup: \"%s\"\n", std_dup ? std_dup : "NULL");

        // Check if both strings are identical
        if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0) {
            printf("   Result: Pass\n");
        } else {
            printf("   Result: Fail\n");
        }

        // Free duplicated strings
        free(ft_dup);
        free(std_dup);

        printf("\n");
    }

    return 0;
}

*/