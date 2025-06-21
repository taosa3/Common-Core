/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:50:48 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/07 17:56:39 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_close(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

void	print_error(const char *msg, t_game *game)
{
	if (game)
		cleanup(game);
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	print_win(t_game *game)
{
	ft_printf("\n========================================\n");
	ft_printf("   You finished the game with %d moves   ", game->player.moves);
	ft_printf("\n========================================\n");
	ft_close(game);
}
