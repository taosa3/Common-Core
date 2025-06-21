/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:32:52 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/07 18:33:19 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	handle_direction_keys(int keycode, t_game *game)
{
	if (keycode == XK_a || keycode == XK_Left)
		move_player(game, 'a');
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 'd');
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game, 'w');
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 's');
}

static int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("You didn't finish the game :(\n");
		ft_close(game);
	}
	else if (!game->player.finished)
		handle_direction_keys(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close, game);
}
