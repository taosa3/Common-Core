/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:30:58 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/01 17:32:52 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char test_chars[] = {'A', 'B', 'C', 'Z', 'a', 'b', 'c', '1', '!', '\0'};
    int i;

    printf("Testing ft_tolower against standard tolower:\n");
    printf("%-5s %-15s %-15s\n", "Char", "ft_tolower", "tolower");
    
    for (i = 0; test_chars[i] != '\0'; i++)
    {
        char c = test_chars[i];
        printf("%-5c %-15c %-15c\n", c, ft_tolower(c), tolower(c));
    }

    return 0;
}

*/