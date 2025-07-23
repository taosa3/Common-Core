/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:57:47 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 21:01:22 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *av)
{
	int	len;

	if (!av)
		return (0);
	len = ft_strlen(av) - 1;
	if (av[len] == 'r' && av[len - 1] == 'e' && av[len - 2] == 'b' && \
av[len - 3] == '.')
		return (1);
	return (0);
}

void	setup_game(t_game *game, char *path)
{
	game->mlx = mlx_init();
	game->map.grid = read_map(game, path);
	game->map.copy = read_map(game, path);
	mlx_get_screen_size(game->mlx, &game->win_x, &game->win_y);
}

int	check_args_and_map(int ac, char **av, t_game *game)
{
	if (ac != 2)
	{
		ft_printf("Bad syntax:\n./so_long ./maps/<maps>.ber\n");
		return (0);
	}
	if (!check_ber_extension(av[1]))
		print_error("Invalid map file extension.", game);
	setup_game(game, av[1]);
	if (!check_map(game))
		print_error("Invalid map.", game);
	return (1);
}
