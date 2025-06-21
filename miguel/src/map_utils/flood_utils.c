/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:52:55 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 15:54:54 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	flood_fill(t_game *game, int y, int x, char marker)
{
	if (y < 0 || x < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	if (game->map.copy[y][x] == '1' || game->map.copy[y][x] == marker)
		return ;
	if (game->map.copy[y][x] == 'C')
		game->map.copy[y][x] = '0';
	if (game->map.copy[y][x] == 'E')
	{
		game->map.copy[y][x] = marker;
		return ;
	}
	game->map.copy[y][x] = marker;
	flood_fill(game, y + 1, x, marker);
	flood_fill(game, y - 1, x, marker);
	flood_fill(game, y, x + 1, marker);
	flood_fill(game, y, x - 1, marker);
}

void	find_player_position(t_game *game, int *py, int *px)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.copy[y])
	{
		x = 0;
		while (game->map.copy[y][x])
		{
			if (game->map.copy[y][x] == 'P')
			{
				*py = y;
				*px = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
