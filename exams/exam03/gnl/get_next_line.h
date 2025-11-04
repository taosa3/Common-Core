#ifndef GNL
#define GNL

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif