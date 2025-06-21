/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:15:39 by anmiguel          #+#    #+#             */
/*   Updated: 2025/03/08 15:20:44 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_format(va_list *args, char symbol)
{
	if (symbol == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (symbol == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (symbol == 'p')
		return (ft_putptr(va_arg(*args, void *), 0));
	else if (symbol == 'd' || symbol == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (symbol == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (symbol == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (symbol == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (symbol == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		print_output;
	int		output;

	if (!format)
		return (-1);
	print_output = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
			output = ft_output_format(&arguments, *++format);
		else
			output = ft_putchar(*format);
		if (output < 0)
		{
			va_end(arguments);
			return (-1);
		}
		print_output += output;
		format++;
	}
	va_end(arguments);
	return (print_output);
}

/*

int main(void)
{
    int result;

    // Test ft_printf with various types
    result = ft_printf("Testing characters: %c, %c\n", 'A', 'B');
    write(1, "Characters printed: ", 20);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("Testing string: %s\n", "Hello, World!");
    write(1, "String printed: ", 16);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("Testing pointer: %p\n", (void *)0x123abc);
    write(1, "Pointer printed: ", 18);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("Testing integer: %d\n", 12345);
    write(1, "Integer printed: ", 17);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("Testing unsigned: %u\n", 4294967295);
    write(1, "Unsigned printed: ", 18);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("Testing hex lowercase: %x\n", 255);
    write(1, "Hex lowercase printed: ", 23);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("Testing hex uppercase: %X\n", 255);
    write(1, "Hex uppercase printed: ", 23);
    ft_putnbr(result);
    write(1, "\n", 1);

    result = ft_printf("%");
	printf("%");
    write(1, "Percent sign printed: ", 22);
    ft_putnbr(result);
    write(1, "\n", 1);

    return (0);
}

*/