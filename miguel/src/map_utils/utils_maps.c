/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:38:16 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/10 14:05:25 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_rectangular(t_game *game)
{
	int	len;

	if (!game->map.grid)
		return (0);
	len = 1;
	while (game->map.grid[len])
	{
		if (ft_strlen(game->map.grid[len]) != ft_strlen(game->map.grid[0]))
			return (0);
		len++;
	}
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x] || map[y - 1][x])
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (map[y])
	{
		len = ft_strlen(map[y]);
		if (map[y][0] != '1' || map[y][len - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	has_valid_entities(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->map.n_players = 0;
	game->map.n_exits = 0;
	game->map.n_collectibles = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'P')
				game->map.n_players++;
			else if (game->map.grid[y][x] == 'E')
				game->map.n_exits++;
			else if (game->map.grid[y][x] == 'C')
				game->map.n_collectibles++;
			x++;
		}
		y++;
	}
	return (game->map.n_players == 1 && game->map.n_exits == 1
		&& game->map.n_collectibles > 0);
}

static int	contains_only_valid_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("01PEC", map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!game || !game->map.grid || !game->map.grid[0])
		print_error("Map is empty or failed to load.", game);
	if (!is_rectangular(game))
		print_error("Map is not rectangular.", game);
	if (!is_surrounded_by_walls(game->map.grid))
		print_error("Map is not surrounded by walls.", game);
	if (!has_valid_entities(game))
		print_error("Map must contain 1 P, 1 E, and at least 1 C.", game);
	if (!contains_only_valid_chars(game->map.grid))
		print_error("Invalid characters on map (only P, E, C, 1, 0 allowed).",
			game);
	if (!check_win(game))
		print_error("Map is not winnable (no valid path to all C and E).",
			game);
	return (1);
}
