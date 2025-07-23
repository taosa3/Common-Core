/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafonso <tafonso@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:14:20 by tafonso           #+#    #+#             */
/*   Updated: 2025/07/12 17:50:06 by tafonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_bytes;

	line = NULL;
	read_bytes = 1;
	while (fd >= 0 && BUFFER_SIZE > 0 && read_bytes > 0)
	{
		if (!buffer[0])
		{
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes < 0)
				return (free(line), NULL);
			buffer[read_bytes] = '\0';
		}
		else
		{
			line = ft_strjoin_gnl(line, buffer);
			if (!line)
				return (NULL);
			if (line[ft_strlen_flag(line, 1) - 1] == '\n')
				break ;
		}
	}
	return (line);
}
