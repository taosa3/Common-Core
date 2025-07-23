/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:17:06 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/05 10:03:51 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

int	puthex_x(unsigned int n, int flag)
{
	char	*hex;
	int		len;

	len = 1;
	if (flag)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		len += puthex_x(n / 16, flag);
	print_char(hex[n % 16]);
	return (len);
}
