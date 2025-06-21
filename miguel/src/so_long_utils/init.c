/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:05:59 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 15:34:14 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	load_images(t_game *game)
{
	game->images.floor = mlx_xpm_file_to_image(game->mlx, \
		"textures/ground.xpm", &game->images.width, &game->images.height);
	game->images.wall = mlx_xpm_file_to_image(game->mlx, \
		"textures/Wall.xpm", &game->images.width, &game->images.height);
	game->images.player = mlx_xpm_file_to_image(game->mlx, \
		"textures/F_Player.xpm", &game->images.width, &game->images.height);
	game->images.collectible = mlx_xpm_file_to_image(game->mlx, \
		"textures/collect.xpm", &game->images.width, &game->images.height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit.xpm", &game->images.width, &game->images.height);
}

void	validate_window_fits_map(t_game *game)
{
	int	map_pixel_width;
	int	map_pixel_height;
	int	lines;

	lines = 0;
	map_pixel_width = ft_strlen(game->map.grid[0]) * 64;
	while (game->map.grid[lines])
		lines++;
	map_pixel_height = lines * 64;
	game->map.width = map_pixel_width;
	game->map.height = map_pixel_height;
	if (map_pixel_width > game->win_width
		|| map_pixel_height > game->win_height)
		print_error("Map is too big for the screen.", game);
}

void	init_game(t_game *game)
{
	validate_window_fits_map(game);
	game->win = mlx_new_window(game->mlx, \
		game->map.width, game->map.height, "so_long");
	game->player.moves = 0;
	game->player.finished = 0;
	load_images(game);
	draw_game(game);
}
