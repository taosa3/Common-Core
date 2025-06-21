/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:05:30 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/21 13:40:28 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(char *s, char terminator)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != terminator)
		i++;
	if (s[i] && s[i] == terminator)
		i++;
	return (i);
}

void	shift_buffer(char *buffer, size_t offset)
{
	size_t	i;

	i = 0;
	while (buffer[offset + i])
	{
		buffer[i] = buffer[offset + i];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_join_buffer(char *s1, char *s2)
{
	char	*arr_str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_linelen(s1, 0);
	len_s2 = ft_linelen(s2, '\n');
	arr_str = malloc(len_s1 + len_s2 + 1);
	if (!arr_str)
		return (free(s1), NULL);
	arr_str[len_s1 + len_s2] = '\0';
	i = -1;
	while (++i < len_s1)
		arr_str[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		arr_str[len_s1 + i] = s2[i];
	free(s1);
	i = -1;
	shift_buffer(s2, len_s2);
	return (arr_str);
}
