/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:22:07 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 18:28:49 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
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