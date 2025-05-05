/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:34:36 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/04 19:22:04 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	print_char(char c);
int	print_str(char *str);
int	print_num(int num);
int	print_unsigned(unsigned int num);
int	print_ptr(void *ptr);
int	puthex_x(unsigned int n, int flag);
int	ft_printf(const char *format, ...);

#endif