/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:54:19 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 17:44:18 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*start;
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (start);
}

/*

#include <stdio.h>

char example_func(unsigned int i, char c)
{
    // Example function that transforms the character based on its index.
    // For simplicity, let's just return the character shifted by the index.
    return c + i;
}

int main(void)
{
    char *str = "abcdef";
    char *result;

    // Apply ft_strmapi with the example function
    result = ft_strmapi(str, example_func);

    if (result)
    {
        printf("Original string: %s\n", str);
        printf("Transformed string: %s\n", result);
        free(result);  // Free the memory allocated by ft_strmapi
    }
    else
    {
        printf("Error: ft_strmapi returned NULL\n");
    }

    return 0;
}

*/