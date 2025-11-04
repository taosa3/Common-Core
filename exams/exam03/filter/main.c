//takes a string as argmument and waits for the user to input a string and
//and if there is the same string in the argument it prints it with X like it's censored

#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE (1000 + 1)

int main(int ac, char **av)
{
	char *buffer;
	int read_bytes = 0;

	read_bytes = read(0, buffer, BUFFER_SIZE);
}