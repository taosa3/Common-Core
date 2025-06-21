/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:24:52 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/01 17:29:24 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char test_chars[] = {'a', 'b', 'c', 'z', 'A', 'B', 'Z', '1', '!', '\0'};
    int i;

    printf("Testing ft_toupper against standard toupper:\n");
    printf("%-5s %-15s %-15s\n", "Char", "ft_toupper", "toupper");
    
    for (i = 0; test_chars[i] != '\0'; i++)
    {
        char c = test_chars[i];
        printf("%-5c %-15c %-15c\n", c, ft_toupper(c), toupper(c));
    }

    return 0;
}

*/