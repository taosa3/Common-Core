/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:24:30 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 15:41:14 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_partial_copy(char **copy, int i)
{
	while (--i >= 0)
		free(copy[i]);
	free(copy);
}

char	**duplicate_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_partial_copy(copy, i);
			return (NULL);
		}
	}
	copy[i] = NULL;
	return (copy);
}
