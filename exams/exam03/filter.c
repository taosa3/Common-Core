#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1

char *append_line(char *line, char *buffer)
{
	size_t len_buffer = strlen(buffer);
	size_t len_line = 0;
	if (line)
		len_line = strlen(line);
	line = realloc(line, len_buffer + len_line + 1);
	if (!line)
		return NULL;
	line[len_buffer + len_line] = 0;
	memmove(line + len_line, buffer, len_buffer);
	return line;
}

void filter(char *line, char *needle)
{
	char *start;
	size_t i = 0;
	while ((start = memmem(line, strlen(line), needle, strlen(needle))))
	{
		i = 0;
		while (i < strlen(needle))
		{
			start[i] = '*';
			i++;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		return 1;
	char buffer[BUFFER_SIZE] = "";
	char *line = NULL;
	ssize_t bytes = 0;
	while (1)
	{
		bytes = read(0, buffer, BUFFER_SIZE);
		buffer[bytes] = 0;
		if (bytes < 0)
		{
			fprintf(stderr, "Error: ");
			perror("read");
			return 1;
		}
		if (bytes == 0)
			break ;
		line = append_line(line, buffer);
		if (!line)
		{
			fprintf(stderr, "Error: ");
			perror("realloc");
			return 1;
		}
	}
	filter(line, av[1]);
	printf("%s", line);
	free(line);
	return 0;
}