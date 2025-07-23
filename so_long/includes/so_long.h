/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:50:24 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 21:11:37 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "printf/printf.h"
# include "getnextline/get_next_line.h"
# include "X11/keysym.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*player;
	void	*collectible;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit_with_player;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	char	**grid;
	char	**copy;
	int		width;
	int		height;
	int		n_players;
	int		n_collectables;
	int		n_exits;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	t_img		images;
	t_map		map;
	t_player	player;
}				t_game;

int		check_ber_extension(char *av);
void	setup_game(t_game *game, char *path);
int		check_args_and_map(int ac, char **av, t_game *game);
int		ft_close(t_game *game);
void	print_error(char *msg, t_game *game);
char	**read_map(t_game *game, char *path);
int		check_map(t_game *game);
int		check_winnable(t_game *game);
void	find_player_position(t_game *game, int *px, int *py);
void	flood_fill(t_game *game, int y, int x);
void	check_if_window_fits_map(t_game *game);
void	init_game(t_game *game);
void	draw_game(t_game *game);
void	gameplay(t_game *game);
void	movement(t_game *game, char key);
void	player_image(t_game *game, char key);
void	get_direction(int *x, int *y, char key);

//Cleanup:
void	free_map(char **map);
void	free_images(t_game *game);
void	cleanup(t_game *game);

#endif