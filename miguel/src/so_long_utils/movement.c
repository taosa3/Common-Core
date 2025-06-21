/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:22:26 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/07 18:31:02 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	update_player_image(t_game *game, char key)
{
	mlx_destroy_image(game->mlx, game->images.player);
	if (key == 'w')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
			"textures/B_Player.xpm", &game->images.width, &game->images.height);
	else if (key == 's')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
			"textures/F_Player.xpm", &game->images.width, &game->images.height);
	else if (key == 'a')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
			"textures/L_Player.xpm", &game->images.width, &game->images.height);
	else if (key == 'd')
		game->images.player = mlx_xpm_file_to_image(game->mlx, \
			"textures/R_Player.xpm", &game->images.width, &game->images.height);
}

static void	get_direction_delta(char key, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (key == 'w')
		*dy = -1;
	else if (key == 's')
		*dy = 1;
	else if (key == 'a')
		*dx = -1;
	else if (key == 'd')
		*dx = 1;
}

static void	update_player_position(t_game *game, int dx, int dy)
{
	int	px;
	int	py;

	px = game->player.x;
	py = game->player.y;
	game->map.grid[py][px] = '0';
	game->map.grid[py + dy][px + dx] = 'P';
	game->player.x += dx;
	game->player.y += dy;
	game->player.moves++;
	ft_printf("%d\n", game->player.moves);
	draw_game(game);
}

static void	process_player_movement(t_game *game, int dx, int dy)
{
	int		px;
	int		py;
	char	target;

	px = game->player.x;
	py = game->player.y;
	target = game->map.grid[py + dy][px + dx];
	if (target == '1' || (target == 'E' && game->map.n_collectibles > 0))
		return ;
	if (target == 'E' && game->map.n_collectibles == 0)
	{
		game->player.finished = 1;
		print_win(game);
	}
	if (target == 'C')
		game->map.n_collectibles--;
	update_player_position(game, dx, dy);
}

void	move_player(t_game *game, char key)
{
	int	dx;
	int	dy;

	get_direction_delta(key, &dx, &dy);
	update_player_image(game, key);
	process_player_movement(game, dx, dy);
}
