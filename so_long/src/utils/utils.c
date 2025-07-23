/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:57:44 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 20:59:53 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

void	print_error(char *msg, t_game *game)
{
	if (game)
		cleanup(game);
	ft_printf("Error:\n%s\n", msg);
	exit(1);
}
