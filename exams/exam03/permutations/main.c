/*take a string as argument and print all the permutations of the string, so "ABC" has 6
and order by alphabet */

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
	char temp;

	temp = *x;
	*x = *y;
	*y = temp;
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
	while (i <= end)
	{
		swap(str + start, str + i);
		permute(str, start + 1, end);
		swap(str + start, str + i);
		i++;
	}
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int i;

	if (ac != 2)
		return (1);
	i = ft_strlen(av[1]);
	order_alphabetic(av[1], i);
	permute(av[1], 0, i - 1);
	return (0);
}