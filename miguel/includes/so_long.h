/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:42:45 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 16:07:32 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Standard libraries
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// Custom project headers
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

// External libraries
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

// Image resources
typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	int		width;
	int		height;
}				t_img;

// Map structure
typedef struct s_map
{
	char	**grid;
	char	**copy;
	int		width;
	int		height;
	int		n_collectibles;
	int		n_exits;
	int		n_players;
	int		valid_collectibles;
	int		valid_exits;
}				t_map;

// Player info
typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		finished;
}				t_player;

// Main game state
typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_img		images;
	t_map		map;
	t_player	player;
}				t_game;

// ----------- UTILS ----------

int		check_ber_extension(char *argv);
void	print_error(const char *msg, t_game *game);
void	find_player_position(t_game *game, int *py, int *px);

// ----------- SETUP ----------

void	setup_game(t_game *game, char *path);
int		valid_args_and_map(int argc, char **argv, t_game *game);
void	validate_window_fits_map(t_game *game);
void	init_game(t_game *game);

// ----------- MAP ----------

char	**map_read(char *path, t_game *game);
int		check_map(t_game *game);
int		check_win(t_game *game);
char	**duplicate_map(char **map);
void	flood_fill(t_game *game, int y, int x, char marker);

// ----------- GAME ----------

int		draw_game(t_game *game);
void	move_player(t_game *game, char key);
void	gameplay(t_game *game);
void	print_win(t_game *game);

// ----------- CLEANUP --------

void	free_map(char **map);
void	free_images(t_game *game);
void	cleanup(t_game *game);
int		ft_close(t_game *game);

#endif
