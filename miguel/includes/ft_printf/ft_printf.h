/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:06:08 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/08 17:46:30 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

# define DEX "0123456789"
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

// helper functions

// chars or strings
int				ft_putchar(char c);
int				ft_putstr(char *s);

// numbers
int				ft_putnbr(int n);
int				ft_putnbr_unsigned(unsigned int n);
int				ft_puthex(unsigned long n, int uppercase);

// pointers
int				ft_putptr(void *n, int uppercase);

// main function
int				ft_printf(const char *format, ...);

#endif