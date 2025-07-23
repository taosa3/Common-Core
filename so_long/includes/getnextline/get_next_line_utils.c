/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:49 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/12 17:50:09 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_flag(char *str, int flag)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (flag)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	else
		while (str[i])
			i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen_flag(s1, 0);
	lens2 = ft_strlen_flag(s2, 1);
	join = malloc(lens1 + lens2 + 1);
	if (!join)
		return (free(s1), NULL);
	join[lens1 + lens2] = '\0';
	i = -1;
	while (++i < lens1)
		join[i] = s1[i];
	i = -1;
	while (++i < lens2)
		join[lens1 + i] = s2[i];
	free(s1);
	i = -1;
	while (s2[lens2 + ++i])
		s2[i] = s2[lens2 + i];
	s2[i] = '\0';
	return (join);
}
