#include <stdio.h>

void swap(char *x, char *y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void order_alphabetic(char *str, int len)
{
	int i = 0;
	int j;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (str[j] > str[j + 1])
				swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

void permute(char *str, int start, int end)
{
	int i = start;
	if (start == end)
		puts(str);
	order_alphabetic(str + start, end - start + 1);
	while (i <= end)
	{
		swap(str + start, str + i);
		permute(str, start + 1, end);
		swap(str + start, str + i);
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		return 1;
	int len = ft_strlen(av[1]);
	permute(av[1], 0, len - 1);
}