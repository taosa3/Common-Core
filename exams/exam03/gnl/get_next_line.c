#include "get_next_line.h"

static size_t ft_strlen(char *str, int flag)
{
	size_t i = 0;
	if (!str)
		return (0);
	if (flag)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	else
		while (str[i])
			i++;
	return (i);
}
static char *strjoin2(char *line, char *buffer)
{
	char *join;
	int i;
	size_t len1 = ft_strlen(line, 0);
	size_t len2 = ft_strlen(buffer, 1);

	join = malloc(len1 + len2 + 1);
	if (!join)
		return (free(line), NULL);
	join[len1 + len2] = 0;
	i = 0;
	while (i < len1)
	{
		join[i] = line[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		join[len1 + i] = buffer[i];
		i++; 
	}
	i = 0;
	while (buffer[len2 + i])
	{
		buffer[i] = buffer[len2 + i];
		i++;
	}
	buffer[i] = '\0';
	free(line);
	return (join);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line = NULL;
	ssize_t read_bytes;

	read_bytes = 1;
	while (fd >= 0 && BUFFER_SIZE >= 0 && read_bytes > 0)
	{
		if (!buffer[0])
		{
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes < 0)
				return (free(line), NULL);
			buffer[read_bytes] = 0;
		}
		else
		{
			line = strjoin2(line, buffer);
			if (!line)
				return (NULL);
			if (line[ft_strlen(line, 1) - 1] == '\n')
				break ;
		}
	}
	return (line);
}