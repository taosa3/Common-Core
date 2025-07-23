/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:58:02 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/17 15:04:03 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

static	void	draw_tile(t_game *game, int y, int x)
{
	if (game->map.grid[y][x] == '1')
		put_image(game, game->images.wall, x, y);
	else if (game->map.grid[y][x] == '0')
		put_image(game, game->images.floor, x, y);
	else if (game->map.grid[y][x] == 'C')
		put_image(game, game->images.collectible, x, y);
	else if (game->map.grid[y][x] == 'E')
		put_image(game, game->images.exit, x, y);
	else if (game->map.grid[y][x] == 'P')
		put_image(game, game->images.floor, x, y);
}

void	check_if_window_fits_map(t_game *game)
{
	int	map_pixel_y;
	int	map_pixel_x;

	map_pixel_y = game->map.height * 64;
	map_pixel_x = game->map.width * 64;
	if (map_pixel_y > game->win_y || map_pixel_x > game->win_x)
		print_error("Map doesn't fit in window", game);
}

void	draw_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			draw_tile(game, y, x);
			x++;
		}
		y++;
	}
	if (game->map.grid[game->player.y][game->player.x] == 'E')
		put_image(game, game->images.exit_with_player, \
game->player.x, game->player.y);
	else
		put_image(game, game->images.player, game->player.x, game->player.y);
}
