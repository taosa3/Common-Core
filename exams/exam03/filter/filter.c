#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

void filter(char *line, char *delimiter)
{
	char *start;
	int i;
	while ((start = memmem(line, strlen(line), delimiter, strlen(delimiter))))
	{
		i = 0;
		while ((size_t)i < strlen(delimiter))
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
	size_t len_line = 0;
	ssize_t bytes_read = 0;
	while (1)
	{
		bytes_read = read(0, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			fprintf(stderr, "Error: ");
			perror("read");
			return 1;
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (line)
			len_line = strlen(line);
		line = realloc(line, len_line + bytes_read + 1);
		if (!line)
		{
			fprintf(stderr, "Error: ");
			perror("realloc");
			return 1;
		}
		line[len_line + bytes_read] = 0;
		memmove(line + len_line, buffer, bytes_read);
	}
	filter(line, av[1]);
	printf("%s", line);
}