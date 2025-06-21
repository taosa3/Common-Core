/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:51:16 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 19:16:11 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

/*

#include <stdio.h>

int main(void)
{
    // Test ft_putnbr_fd with standard output (file descriptor 1)
    printf("Testing ft_putnbr_fd with standard output:\n");
    
    printf("Expected output: 42\nOutput: ");
    ft_putnbr_fd(42, 1);
    printf("\n");

    printf("Expected output: -42\nOutput: ");
    ft_putnbr_fd(-42, 1);
    printf("\n");

    printf("Expected output: 0\nOutput: ");
    ft_putnbr_fd(0, 1);
    printf("\n");

    printf("Expected output: INT_MAX\nOutput: ");
    ft_putnbr_fd(2147483647, 1);
    printf("\n");

    printf("Expected output: INT_MIN\nOutput: ");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");

    return 0;
}

*/