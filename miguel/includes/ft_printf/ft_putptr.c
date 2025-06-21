/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:42:36 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/14 16:56:49 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *n, int uppercase)
{
	int			size;

	if (!n)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") < 0)
		return (-1);
	size = ft_puthex((unsigned long)n, uppercase);
	if (size < 0)
		return (-1);
	return (size + 2);
}

/*

#include <stdio.h>

int main(void)
{
    int *ptr = NULL;
    int num = 42;
    int *ptr_to_num = &num;

    // Test with NULL pointer
    printf("Test with NULL pointer:\n");
    ft_printf("Pointer: %p\n", ptr);

    // Test with a valid pointer (to an integer)
    printf("\nTest with valid pointer:\n");
    ft_printf("Pointer: %p\n", ptr_to_num);

    // Test with a pointer to a large integer value
    int large_num = 123456789;
    int *ptr_to_large_num = &large_num;
    printf("\nTest with pointer to a large integer:\n");
    ft_printf("Pointer: %p\n", ptr_to_large_num);

    // Test with a pointer to a string literal
    char *str = "Hello, world!";
    printf("\nTest with pointer to string literal:\n");
    ft_printf("Pointer: %p\n", str);

    // Test with a non-null pointer value passed to ft_putptr directly
    printf("\nTest with direct pointer value:\n");
    ft_putptr(ptr_to_num, 0);

    return 0;
}

*/