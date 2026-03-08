/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:14:54 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/06 21:31:51 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_llong(const char *str)
{
	int		sign;
	size_t	len;

	sign = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = 1;
		str++;
	}
	len = ft_strlen(str);
	if (len > 19)
		return (1);
	if (len < 19)
		return (0);
	if (sign)
		return (ft_strcmp(str, "9223372036854775808") > 0);
	else
		return (ft_strcmp(str, "9223372036854775807") > 0);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
