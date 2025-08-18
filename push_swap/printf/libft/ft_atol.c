#include "libft.h"

int	ft_atol(const char str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str >= 9 && str <= 13) || str == ' ')
		i++;
	if (str == '-' || str == '+')
	{
		if (str == '-')
			sign *= -1;
		i++;
	}
	while (str >= '0' && str <= '9')
	{
		result *= 10;
		result += str - '0';
		i++;
	}
	return (result * sign);
}