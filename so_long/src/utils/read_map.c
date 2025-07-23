/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:18:21 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/16 20:57:54 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	check_invalid_newline(char *line, char *map_str, t_game *game)
{
	if (line && line[0] == '\n')
	{
		free(line);
		free(map_str);
		print_error("Invalid new line in map.", game);
	}
}

static	char	*read_map_file(int fd, t_game *game)
{
	char	*map_str;
	char	*line;
	char	*temp;

	map_str = ft_strdup("");
	game->map.height = 0;
	game->map.width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_invalid_newline(line, map_str, game);
		if (game->map.height == 0)
			game->map.width = ft_strlen(line)
				- (line[ft_strlen(line) - 1] == '\n');
		temp = map_str;
		map_str = ft_strjoin(temp, line);
		free(temp);
		free(line);
		game->map.height++;
		line = get_next_line(fd);
	}
	return (map_str);
}

char	**read_map(t_game *game, char *path)
{
	int		fd;
	char	*map_str;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open the file.", game);
	map_str = read_map_file(fd, game);
	map = ft_split(map_str, '\n');
	free(map_str);
	close(fd);
	return (map);
}
