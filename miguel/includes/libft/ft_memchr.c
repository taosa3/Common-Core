/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:38:47 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 14:21:23 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s + i) == (unsigned char) c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hello, world!";
    int ch = 'o';
    size_t n = 13;  // Number of bytes to search

    // Test ft_memchr
    char *result1 = ft_memchr(str, ch, n);
    if (result1)
        printf("ft_memchr: Found '%c' at position: %ld\n", ch, result1 - str);
    else
        printf("ft_memchr: '%c' not found in the first %zu bytes\n", ch, n);

    // Test standard memchr for comparison
    char *result2 = memchr(str, ch, n);
    if (result2)
        printf("memchr: Found '%c' at position: %ld\n", ch, result2 - str);
    else
        printf("memchr: '%c' not found in the first %zu bytes\n", ch, n);

    return 0;
}

*/