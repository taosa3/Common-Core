/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:43:24 by tafonso           #+#    #+#             */
/*   Updated: 2025/04/19 22:55:15 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char delimiter)
{
	int	count;
	int	i;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != delimiter && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == delimiter)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **result, int j)
{
	while (--j >= 0)
		free(result[j]);
	free(result);
}

static char	*word_dup(const char *start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	split_words(char **result, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j++] = word_dup(&s[start], i - start);
			if (result[j - 1] == NULL)
			{
				free_all(result, j - 1);
				return (0);
			}
		}
		else
			i++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (split_words(result, s, c) == 0)
	{
		free_all(result, word_count);
		return (NULL);
	}
	return (result);
}
