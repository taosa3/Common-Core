/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:42 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 18:19:29 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*

#include <stdio.h>

int main(void)
{
    // Test ft_putchar_fd with different characters and file descriptors

    // Write a single character 'A' to the standard output (file descriptor 1)
    printf("Testing ft_putchar_fd with standard output:\n");
    ft_putchar_fd('A', 1);

    // Write a single character 'B' to the standard error (file descriptor 2)
    printf("\nTesting ft_putchar_fd with standard error:\n");
    ft_putchar_fd('B', 2);

    // Optionally, you can test with other file descriptors, 
	// but here we use standard output and error.

    return 0;
}

*/