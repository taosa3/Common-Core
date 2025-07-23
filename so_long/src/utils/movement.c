/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:14:23 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 21:14:29 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	move_player(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player.x + x;
	new_y = game->player.y + y;
	tile = game->map.grid[new_y][new_x];
	if (tile == 'C')
	{
		game->map.grid[new_y][new_x] = '0';
		game->map.n_collectables--;
	}
	game->player.y += y;
	game->player.x += x;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	draw_game(game);
}

void	movement(t_game *game, char key)
{
	int	x;
	int	y;
	int	next;

	get_direction(&x, &y, key);
	next = game->map.grid[game->player.y + y][game->player.x + x];
	if (next == '1')
		return ;
	if (next == 'E' && game->map.n_collectables == 0)
	{
		ft_printf("==================!!!!YOU WON!!!!====================");
		ft_close(game);
	}
	player_image(game, key);
	move_player(game, x, y);
}
