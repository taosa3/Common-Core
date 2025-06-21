/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:51:16 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/14 16:59:15 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	num;
	int				size;

	num = n;
	size = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		size++;
		num = -num;
	}
	if (num >= 10)
		size += ft_putnbr(num / 10);
	if (ft_putchar((num % 10) + '0') < 0)
		return (-1);
	size++;
	return (size);
}

static int	print_unsigned(unsigned int n, int *size)
{
	if (n >= 10 && print_unsigned(n / 10, size) < 0)
		return (-1);
	*size = *size + 1;
	return (write(1, &DEX[n % 10], 1));
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (print_unsigned(n, &size) < 0)
		return (-1);
	return (size);
}

static ssize_t	print_hex(unsigned long n, char *base, ssize_t *size)
{
	if (n >= 16 && print_hex(n / 16, base, size) < 0)
		return (-1);
	*size = *size + 1;
	return (write(1, &base[n % 16], 1));
}

int	ft_puthex(unsigned long n, int uppercase)
{
	ssize_t		size;
	char		*base;

	size = 0;
	if (uppercase)
		base = HEX_UP;
	else
		base = HEX_LOW;
	if (print_hex(n, base, &size) < 0)
		return (-1);
	return (size);
}

/*

int main(void)
{
    int result;

    // Test ft_putnbr with various values
    result = ft_putnbr(12345);
    write(1, "\n", 1);
    ft_putnbr(-12345);
    write(1, "\n", 1);

    // Test ft_putnbr with edge cases
    ft_putnbr(0);
    write(1, "\n", 1);
    ft_putnbr(-2147483648);
    write(1, "\n", 1);

    // Print the result of the last function call (optional, for debugging)
    write(1, "ft_putnbr result: ", 18);
    ft_putnbr(result);
    write(1, "\n\n", 2);

    // Test ft_putnbr_unsigned with various unsigned values
    ft_putnbr_unsigned(0);
    write(1, "\n", 1);
    ft_putnbr_unsigned(4294967295); // Maximum value for unsigned int
    write(1, "\n", 1);
    ft_putnbr_unsigned(987654321);
    write(1, "\n", 1);

    // Test ft_puthex with uppercase and lowercase options
    write(1, "Hex lowercase: ", 15);
    ft_puthex(255, 0);  // Should print "ff"
    write(1, "\n", 1);
    
    write(1, "Hex uppercase: ", 15);
    ft_puthex(255, 1);  // Should print "FF"
    write(1, "\n", 1);

    // Test ft_puthex with larger values
    write(1, "Hex lowercase large number: ", 27);
    ft_puthex(305419896, 0);  // Example large hex number
    write(1, "\n", 1);

    write(1, "Hex uppercase large number: ", 27);
    ft_puthex(305419896, 1);
    write(1, "\n", 1);

    return 0;
}

*/