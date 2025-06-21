/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:01:15 by anmiguel          #+#    #+#             */
/*   Updated: 2025/06/09 18:02:21 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_invalid_newline(char *line, char *map_data, t_game *game)
{
	if (line && *line == '\n')
	{
		free(line);
		free(map_data);
		print_error("Invalid new line in map.", game);
	}
}

static char	*read_map_file(int fd, t_game *game)
{
	char	*line;
	char	*map_data;
	char	*temp;

	map_data = ft_strdup("");
	game->map.height = 0;
	game->map.width = 0;
	while (1)
	{
		line = get_next_line(fd);
		check_invalid_newline(line, map_data, game);
		if (!line)
			break ;
		if (game->map.height == 0)
			game->map.width = ft_strlen(line)
				- (line[ft_strlen(line) - 1] == '\n');
		temp = map_data;
		map_data = ft_strjoin(temp, line);
		free(temp);
		free(line);
		game->map.height++;
	}
	return (map_data);
}

char	**map_read(char *path, t_game *game)
{
	int		fd;
	char	*map_data;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Failed to open file.", game);
	map_data = read_map_file(fd, game);
	map = ft_split(map_data, '\n');
	free(map_data);
	close(fd);
	return (map);
}
