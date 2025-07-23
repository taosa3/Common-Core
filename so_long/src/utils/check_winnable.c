/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_winnable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:58:07 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 21:14:11 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map.height || x >= game->map.width)
		return ;
	if (game->map.copy[y][x] == '1' || game->map.copy[y][x] == 'X')
		return ;
	game->map.copy[y][x] = 'X';
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
}

void	find_player_position(t_game *game, int *px, int *py)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.copy[y])
	{
		x = 0;
		while (game->map.copy[y][x])
		{
			if (game->map.copy[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_winnable(t_game *game)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = 0;
	find_player_position(game, &px, &py);
	game->player.x = px;
	game->player.y = py;
	flood_fill(game, py, px);
	while (game->map.copy[y])
	{
		x = 0;
		while (game->map.copy[y][x])
		{
			if (game->map.copy[y][x] == 'C' || game->map.copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
