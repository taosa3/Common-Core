/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:14:35 by anmiguel          #+#    #+#             */
/*   Updated: 2025/03/08 15:19:04 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_count(const char *str, char c)
{
	int	i;
	int	num_words;

	num_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			num_words++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (num_words);
}

int	skip_delimiters(const char *s, char c, int start)
{
	while (s[start] && s[start] == c)
		start++;
	return (start);
}

char	*fill_words(const char *s, char c, int *start)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[*start + i];
		i++;
	}
	str[i] = '\0';
	*start += len;
	return (str);
}

void	free_str(char **split, int num_word)
{
	int	i;

	i = 0;
	while (i < num_word)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	words = words_count(s, c);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		start = skip_delimiters(s, c, start);
		res[i] = fill_words(s, c, &start);
		if (!res[i])
		{
			free_str(res, i);
			return (NULL);
		}
		i++;
	}
	return (res);
}

/*

#include <stdio.h>

int main() {
    char str[] = "Hello,world! This is a test.";
    char c = '!';  
// Splitting based on space, comma, exclamation, and period
    char **result;
    int i;

    // Call ft_split
    result = ft_split(str, c);

    // Print each word from the result
    i = 0;
    while (result[i]) {
        printf("Word %d: %s\n", i + 1, result[i]);
        free(result[i]); // Free each word after use
        i++;
    }

    free(result); // Free the array of pointers

    return 0;
}
*/