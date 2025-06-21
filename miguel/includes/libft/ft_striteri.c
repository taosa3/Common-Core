/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:45:26 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 17:56:10 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}

/*

#include <stdio.h>

void example_func(unsigned int i, char *c)
{
    *c = *c + i;  // Add the index to the character
}

int main(void)
{
    char str[] = "abcdef";  // A mutable string for testing

    printf("Original string: %s\n", str);

    // Call ft_striteri with the example function
    ft_striteri(str, example_func);

    // After ft_striteri, the string should be modified
    printf("Modified string: %s\n", str);

    return 0;
}

*/