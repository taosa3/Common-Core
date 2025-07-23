/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:30:58 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/17 14:33:15 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	load_images(t_game *game)
{
	game->images.collectible = mlx_xpm_file_to_image(game->mlx, \
"textures/collectable.xpm", &game->images.width, &game->images.height);
	game->images.player = mlx_xpm_file_to_image(game->mlx, \
"textures/S_character.xpm", &game->images.width, &game->images.height);
	game->images.floor = mlx_xpm_file_to_image(game->mlx, \
"textures/floor.xpm", &game->images.width, &game->images.height);
	game->images.wall = mlx_xpm_file_to_image(game->mlx, \
"textures/wall.xpm", &game->images.width, &game->images.height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, \
"textures/exit.xpm", &game->images.width, &game->images.height);
	game->images.exit_with_player = mlx_xpm_file_to_image(game->mlx, \
"textures/B_exit.xpm", &game->images.width, &game->images.height);
}

void	init_game(t_game *game)
{
	check_if_window_fits_map(game);
	game->win = mlx_new_window(game->mlx, game->map.width * 64, \
game->map.height * 64, "so_long");
	if (!game->win)
		print_error("Error putting window", game);
	game->player.moves = 0;
	game->images.width = 64;
	game->images.height = 64;
	load_images(game);
	draw_game(game);
}
