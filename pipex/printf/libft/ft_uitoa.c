/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:30:05 by tafonso           #+#    #+#             */
/*   Updated: 2025/05/04 15:57:25 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_len(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned long	nb;

	nb = n;
	len = num_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}
