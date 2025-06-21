/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:06:01 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/02 15:16:30 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/*

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *test_cases[] = {
        "   -12345",
        "42",
        "   +567",
        "abc123",
        "987abc",
        "   -0",
        "+0",
        "2147483647",        // INT_MAX
        "-2147483648",       // INT_MIN
        "    -+42",          // Invalid input
        "   +0000123",       // Leading zeroes
        "9999999999"         // Out of range for int
    };
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        const char *test_str = test_cases[i];
        int std_result = atoi(test_str);
        int ft_result = ft_atoi(test_str);

        printf("Test case \"%s\":\n", test_str);
        printf("   atoi: %d\n", std_result);
        printf("   ft_atoi: %d\n", ft_result);
        printf("   Match: %s\n\n", (std_result == ft_result) ? "Yes" : "No");
    }

    return (0);
}

*/