/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:50:35 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 18:33:00 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->images.floor)
		mlx_destroy_image(game->mlx, game->images.floor);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	if (game->images.player)
		mlx_destroy_image(game->mlx, game->images.player);
	if (game->images.collectible)
		mlx_destroy_image(game->mlx, game->images.collectible);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
}

void	cleanup(t_game *game)
{
	if (game->map.grid)
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
	}
	if (game->map.copy)
	{
		free_map(game->map.copy);
		game->map.copy = NULL;
	}
	free_images(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
