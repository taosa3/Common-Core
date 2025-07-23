/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:12:26 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/17 18:22:12 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_rectangular(t_game *game)
{
	int	i;

	i = 1;
	while (game->map.grid[i])
	{
		if (ft_strlen(game->map.grid[i]) != ft_strlen(game->map.grid[0]))
			return (0);
		i++;
	}
	return (1);
}

static	int	check_surrounded_by_wall(char **map)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
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

static	int	check_if_valid_entities(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->map.n_collectables = 0;
	game->map.n_exits = 0;
	game->map.n_players = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'C')
				game->map.n_collectables++;
			else if (game->map.grid[y][x] == 'P')
				game->map.n_players++;
			else if (game->map.grid[y][x] == 'E')
				game->map.n_exits++;
			x++;
		}
		y++;
	}
	return (game->map.n_players == 1 && game->map.n_exits == 1
		&& game->map.n_collectables >= 1);
}

static	int	check_valid_characters(char **map)
{
	int	x;
	int	y;

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
		print_error("Map failed to load or it's empty.", game);
	if (!check_rectangular(game))
		print_error("Map is not rectangular.", game);
	if (!check_surrounded_by_wall(game->map.grid))
		print_error("Map is not surrounded by walls.", game);
	if (!check_if_valid_entities(game))
		print_error("Map must contain 1-'P', 1-'E' and at least 1-'C'", game);
	if (!check_valid_characters(game->map.grid))
		print_error("Invalid characters in map. ('0','1','P','C','E').", game);
	if (!check_winnable(game))
		print_error("Map is not winnable.", game);
	return (1);
}
