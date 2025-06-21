/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:22:07 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/08 17:46:23 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

/*

#include <stdio.h>

int main(void)
{
    // Test ft_putstr_fd with standard output (file descriptor 1)
    printf("Testing ft_putstr_fd with standard output:\n");
    ft_putstr_fd("Hello, world!\n", 1);

    // Test ft_putstr_fd with standard error (file descriptor 2)
    printf("Testing ft_putstr_fd with standard error:\n");
    ft_putstr_fd("Error: Something went wrong.\n", 2);

    // Test with an empty string
    printf("Testing ft_putstr_fd with an empty string:\n");
    ft_putstr_fd("", 1);

    // Test with a longer string
    printf("Testing ft_putstr_fd with a longer string:\n");
    ft_putstr_fd("This is a longer test string for ft_putstr_fd.\n", 1);

    return 0;
}

*/