//takes a string as argmument and waits for the user to input a string and
//and if there is the same string in the argument it prints it with X like it's censored

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 2

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		return (1);

	char buffer[BUFFER_SIZE];
	char *needle = av[1];
	size_t needle_len = strlen(needle);
	ssize_t	read_bytes;
	while ((read_bytes = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		char *current = buffer;
		char *match;
		while ((match = memmem(current, buffer + read_bytes - current, needle, needle_len)))
		{
			write(1, current, match - current);

			size_t i = 0;
			while (i++ < needle_len)
				write(1, "*", 1);
			current = match + needle_len;
		}
		if (current < buffer + read_bytes)
			write(1, current, buffer + read_bytes - current);
	}
	return (read_bytes < 0);
}