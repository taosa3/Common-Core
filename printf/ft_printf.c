/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:53:56 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/04 19:18:13 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

static	int	handle_format(const	char *format, va_list args, size_t *i)
{
	int	len;

	len = 0;
	(*i)++;
	if (format[*i] == 'c')
		len += print_char(va_arg(args, int));
	else if (format[*i] == 's')
		len += print_str(va_arg(args, char *));
	else if (format[*i] == '%')
		len += write (1, "%", 1);
	else if (format[*i] == 'p')
		len += print_ptr(va_arg(args, void *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		len += print_num(va_arg(args, int));
	else if (format[*i] == 'u')
		len += print_unsigned(va_arg(args, unsigned int));
	else if (format[*i] == 'X')
		len += puthex_x(va_arg(args, unsigned int), 0);
	else if (format[*i] == 'x')
		len += puthex_x(va_arg(args, unsigned int), 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	len;
	size_t	i;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			len += handle_format(format, args, &i);
		else
			len += write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
