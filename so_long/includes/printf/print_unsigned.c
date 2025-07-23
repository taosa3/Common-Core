/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:36:01 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/04 19:17:35 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int	print_unsigned(unsigned int num)
{
	char	*str;
	int		i;

	str = ft_uitoa(num);
	if (!str)
		return (-1);
	i = print_str(str);
	free(str);
	return (i);
}
