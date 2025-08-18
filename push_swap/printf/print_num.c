/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:35:06 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/22 11:52:07 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_num(int num)
{
	char	*str;
	int		i;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	i = print_str(str);
	free(str);
	return (i);
}
