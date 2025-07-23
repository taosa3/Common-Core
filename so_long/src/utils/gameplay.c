/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:57:59 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 21:12:29 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_image(t_game *game, char key)
{
	mlx_destroy_image(game->mlx, game->images.player);
	if (key == 'w')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
"textures/W_character.xpm", &game->images.width, &game->images.height);
	else if (key == 's')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
"textures/S_character.xpm", &game->images.width, &game->images.height);
	else if (key == 'a')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
"textures/A_character.xpm", &game->images.width, &game->images.height);
	else if (key == 'd')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
"textures/D_character.xpm", &game->images.width, &game->images.height);
}

void	get_direction(int *x, int *y, char key)
{
	*x = 0;
	*y = 0;
	if (key == 'w')
		*y = -1;
	else if (key == 's')
		*y = 1;
	else if (key == 'a')
		*x = -1;
	else if (key == 'd')
		*x = 1;
}

static int	handle_keypress(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		ft_printf("Pressed (ESC), leaving game...\n");
		ft_close(game);
	}
	else if (key == XK_w)
		movement(game, 'w');
	else if (key == XK_s)
		movement(game, 's');
	else if (key == XK_a)
		movement(game, 'a');
	else if (key == XK_d)
		movement(game, 'd');
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close, game);
}
