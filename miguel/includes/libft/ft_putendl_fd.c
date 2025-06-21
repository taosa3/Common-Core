/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:42:59 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 18:49:02 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*

#include <stdio.h>

int main(void)
{
    // Test ft_putendl_fd with standard output (file descriptor 1)
    printf("Testing ft_putendl_fd with standard output:\n");
    ft_putendl_fd("Hello, world!", 1);

    // Test ft_putendl_fd with standard error (file descriptor 2)
    printf("Testing ft_putendl_fd with standard error:\n");
    ft_putendl_fd("Error: Something went wrong.", 2);

    // Test with an empty string
    printf("Testing ft_putendl_fd with an empty string:\n");
    ft_putendl_fd("", 1);

    // Test with a longer string
    printf("Testing ft_putendl_fd with a longer string:\n");
    ft_putendl_fd("This is a longer test string for ft_putendl_fd.", 1);

    return 0;
}

*/