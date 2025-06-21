/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:46:28 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/10 15:18:25 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
void print_map(char **map)
{
    int i = 0;
    if (!map) // Handle the case where the map itself is NULL
    {
        printf("Error: Map is NULL.\n");
        return;
    }
    while (map[i]) // Iterate until the null terminator is found
    {
        printf("%s\n", map[i]); // Print the current string followed by a newline
        i++;
    }
}


static void	count_remaining_ce(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	game->map.valid_collectibles = 0;
	game->map.valid_exits = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->map.valid_collectibles++;
			else if (map[y][x] == 'E')
				game->map.valid_exits++;
			x++;
		}
		y++;
	}
}

static int	check_collectibles_path(t_game *game, int py, int px)
{
	if (!game->map.copy)
		print_error("Memory error (copy collectibles)", game);
    print_map(game->map.copy);
	flood_fill(game, py, px, 'X');
    print_map(game->map.copy);
	count_remaining_ce(game, game->map.copy);
	free_map(game->map.copy);
	game->map.copy = NULL;
	return (game->map.valid_collectibles == 0);
}

static int	find_exit_position(char **map, int *ey, int *ex)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				*ey = y;
				*ex = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_exit_path(t_game *game, int py, int px)
{
	int	ex;
	int	ey;

	game->map.copy = duplicate_map(game->map.grid);
	if (!game->map.copy)
		print_error("Memory error (copy collectibles)", game);
	if (!find_exit_position(game->map.copy, &ey, &ex))
	{
		free_map(game->map.copy);
		game->map.copy = NULL;
		return (0);
	}
    print_map(game->map.copy);
	flood_fill(game, py, px, 'V');
    print_map(game->map.copy);
	count_remaining_ce(game, game->map.copy);
	free_map(game->map.copy);
	game->map.copy = NULL;
	return (game->map.valid_exits == 0);
}

int	check_win(t_game *game)
{
	int	px;
	int	py;

	find_player_position(game, &py, &px);
	if (!check_collectibles_path(game, py, px))
	{
		return (0);
	}
	if (!check_exit_path(game, py, px))
	{
		return (0);
	}
	return (1);
}
