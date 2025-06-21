/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:10:55 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/01 18:43:16 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest1[20];
    char *src = "Hello, world!";
    size_t size1 = 10;
    size_t ret1;

    // Testing ft_strlcpy
    ret1 = ft_strlcpy(dest1, src, size1);

    // Output the results
    printf("ft_strlcpy: copied string: \"%s\", 
	length of source: %zu\n", dest1, ret1);

    return 0;
}

*/