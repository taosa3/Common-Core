/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:26:18 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/08 16:51:14 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_size(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str_nmb;
	long	nbr;

	nbr = n;
	size = calc_size(nbr);
	str_nmb = ft_calloc(size + 1, sizeof(char));
	if (!str_nmb)
		return (NULL);
	str_nmb[size] = '\0';
	if (nbr < 0)
	{
		str_nmb[0] = '-';
		nbr = -nbr;
	}
	while (size-- && nbr >= 0)
	{
		if (str_nmb[size] == '-')
			break ;
		str_nmb[size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str_nmb);
}

/*

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *result;

	// Test zero
	result = ft_itoa(0);
	printf("ft_itoa(0) = %s\n", result);
	free(result);

	// Test positive number
	result = ft_itoa(12345);
	printf("ft_itoa(12345) = %s\n", result);
	free(result);

	// Test negative number
	result = ft_itoa(-12345);
	printf("ft_itoa(-12345) = %s\n", result);
	free(result);

	// Test INT_MAX
	result = ft_itoa(INT_MAX);
	printf("ft_itoa(INT_MAX) = %s\n", result);
	free(result);

	// Test INT_MIN
	result = ft_itoa(INT_MIN);
	printf("ft_itoa(INT_MIN) = %s\n", result);
	free(result);

	return 0;
}

*/