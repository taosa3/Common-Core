/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:18:52 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 16:11:13 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr_temp;
	size_t			full_size;

	ptr_temp = malloc(nmemb * size);
	full_size = nmemb * size;
	if (size && full_size / size != nmemb)
		return (NULL);
	if (!ptr_temp)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr_temp);
	ft_bzero(ptr_temp, nmemb * size);
	return (ptr_temp);
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    size_t test_sizes[][2] = {
        {5, sizeof(int)},
        {10, sizeof(char)},
        {0, sizeof(int)},     // Edge case: zero elements
        {5, 0},               // Edge case: element size zero
        {20, sizeof(double)}
    };
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

    for (int i = 0; i < num_tests; i++) {
        size_t nmemb = test_sizes[i][0];
        size_t size = test_sizes[i][1];
        
        // Allocate memory using ft_calloc and calloc
        void *ft_ptr = ft_calloc(nmemb, size);
        void *std_ptr = calloc(nmemb, size);

        printf("Test %d - nmemb: %zu, size: %zu\n", i + 1, nmemb, size);

        // Check if both pointers are null when nmemb or size is zero
        if (nmemb == 0 || size == 0) {
            printf("   ft_calloc returned: %s\n", 
			ft_ptr == NULL ? "NULL" : "Non-NULL");
            printf("   calloc returned: %s\n", 
			std_ptr == NULL ? "NULL" : "Non-NULL");
        } else {
            // Compare memory contents
            int is_equal = memcmp(ft_ptr, std_ptr, nmemb * size) == 0;
            printf("   Memory is zeroed: %s\n", is_equal ? "Yes" : "No");
        }

        // Free allocated memory
        free(ft_ptr);
        free(std_ptr);
    }

    return 0;
}

*/