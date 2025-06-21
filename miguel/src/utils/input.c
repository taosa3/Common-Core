/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:56:00 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/07 18:57:52 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_ber_extension(char *argv)
{
	int	len;

	if (!argv)
		return (0);
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' && \
		argv[len - 3] == '.')
		return (1);
	return (0);
}

void	setup_game(t_game *game, char *path)
{
	game->mlx = mlx_init();
	game->map.grid = map_read(path, game);
	game->map.copy = map_read(path, game);
	mlx_get_screen_size(game->mlx, &game->win_width, &game->win_height);
}

int	valid_args_and_map(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Bad syntax:\n./so_long ./maps/<map>.ber\n");
		return (0);
	}
	if (!check_ber_extension(argv[1]))
		print_error("Invalid map file extension.", game);
	setup_game(game, argv[1]);
	if (!check_map(game))
		print_error("Invalid map.", game);
	return (1);
}
