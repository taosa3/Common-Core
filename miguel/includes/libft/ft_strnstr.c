/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:32:02 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 16:10:29 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *big = "Hello, this is a simple string for testing.";
    const char *little1 = "simple";
    const char *little2 = "notfound";
    const char *little3 = "";
    size_t len = 30;

    // Test case 1: Substring is found within len
    char *result1 = ft_strnstr(big, little1, len);
    printf("ft_strnstr: Searching \"%s\" in \"%s\" within first 
			%zu characters: %s\n",
           little1, big, len, result1 ? result1 : "NULL");

    //char *std_result1 = strnstr(big, little1, len);
    //printf("strnstr: Searching \"%s\" in \"%s\" within first 
	//		%zu characters: %s\n",
    //       little1, big, len, std_result1 ? std_result1 : "NULL");

    // Test case 2: Substring is not found
    char *result2 = ft_strnstr(big, little2, len);
    printf("\nft_strnstr: Searching \"%s\" in \"%s\" within first 
			%zu characters: %s\n",
           little2, big, len, result2 ? result2 : "NULL");

    //char *std_result2 = strnstr(big, little2, len);
    //printf("strnstr: Searching \"%s\" in \"%s\" within first 
	//		%zu characters: %s\n",
    //       little2, big, len, std_result2 ? std_result2 : "NULL");

    // Test case 3: Empty substring (should return the full big string)
    char *result3 = ft_strnstr(big, little3, len);
    printf("\nft_strnstr: Searching \"%s\" in \"%s\" within first 
			%zu characters: %s\n",
           little3, big, len, result3 ? result3 : "NULL");

    //char *std_result3 = strnstr(big, little3, len);
    //printf("strnstr: Searching \"%s\" in \"%s\" within first 
	//		%zu characters: %s\n",
    //       little3, big, len, std_result3 ? std_result3 : "NULL");

    // Test case 4: Length is smaller than the substring's position
    len = 10;
    char *result4 = ft_strnstr(big, little1, len);
    printf("\nft_strnstr: Searching \"%s\" in \"%s\" within first 
			%zu characters: %s\n",
           little1, big, len, result4 ? result4 : "NULL");

    //char *std_result4 = strnstr(big, little1, len);
    //printf("strnstr: Searching \"%s\" in \"%s\" within first 
	//		%zu characters: %s\n",
    //       little1, big, len, std_result4 ? std_result4 : "NULL");

    return 0;
}

*/