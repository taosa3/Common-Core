#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (len < n && str[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}