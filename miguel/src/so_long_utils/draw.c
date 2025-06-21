/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:33:12 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 15:27:58 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

static void	put_player(t_game *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	put_img(game, game->images.player, x, y);
}

static void	put_exit(t_game *game, int x, int y)
{
	if (game->map.n_collectibles == 0)
	{
		mlx_destroy_image(game->mlx, game->images.exit);
		game->images.exit = mlx_xpm_file_to_image(game->mlx,
				"textures/Barrel_Full.xpm",
				&game->images.width,
				&game->images.height);
	}
	put_img(game, game->images.exit, x, y);
}

static void	draw_tile_at(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	if (tile == '1')
	{
		put_img(game, game->images.wall, x, y);
	}
	else if (tile == '0')
	{
		put_img(game, game->images.floor, x, y);
	}
	else if (tile == 'C')
	{
		put_img(game, game->images.collectible, x, y);
	}
	else if (tile == 'P')
	{
		put_player(game, x, y);
	}
	else if (tile == 'E')
	{
		put_exit(game, x, y);
	}
}

int	draw_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			draw_tile_at(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
