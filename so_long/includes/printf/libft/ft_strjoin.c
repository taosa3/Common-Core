/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:32 by tafonso           #+#    #+#             */
/*   Updated: 2025/04/19 22:56:59 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joinstr;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joinstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joinstr == NULL)
		return (NULL);
	while (s1[i])
	{
		joinstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joinstr[i + j] = s2[j];
		j++;
	}
	joinstr[i + j] = '\0';
	return (joinstr);
}
