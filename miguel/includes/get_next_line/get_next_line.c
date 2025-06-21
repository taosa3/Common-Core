/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:05:06 by anmiguel          #+#    #+#             */
/*   Updated: 2024/11/21 13:39:09 by anmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;	

	line = NULL;
	bytes_read = 1;
	while (fd >= 0 && BUFFER_SIZE > 0 && bytes_read > 0)
	{
		if (buffer[0])
		{
			line = ft_join_buffer(line, buffer);
			if (!line)
				return (NULL);
			if (line[ft_linelen(line, '\n') - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			buffer[bytes_read] = '\0';
		}
	}
	return (line);
}

/*
int main(void)
{
	char	*line;

	//terminal input get line
	write(1, "your input: ", 13);
	line = get_next_line(1);
	printf("line: %s", line);
	free(line);
	return(0);
}

*/

/*

int	main(void)
{
	int fd;
	char *line;
	int i = 1;

	fd = open("giant_line.txt", O_RDONLY);
	while(i <= 42)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		i++;
		free(line);
	}
	return(0);
} 
*/