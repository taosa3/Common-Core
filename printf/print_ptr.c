/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:12:06 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/22 11:52:06 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	puthex(uintptr_t n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		puthex(n / 16);
	print_char(hex[n % 16]);
}

int	print_ptr(void *ptr)
{
	uintptr_t	address;
	uintptr_t	temp;
	int			len;

	if (!ptr)
	{
		print_str("0x0");
		return (3);
	}
	address = (uintptr_t)ptr;
	print_str("0x");
	puthex(address);
	len = 2;
	temp = address;
	while (temp)
	{
		temp /= 16;
		len++;
	}
	return (len);
}
