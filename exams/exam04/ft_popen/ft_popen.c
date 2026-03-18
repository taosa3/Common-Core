#include <unistd.h>
#include <stdio.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' || type != 'w'))
		return (-1);
	int fd[2];

	if (pipe(fd))
		return (-1);
	if (type == 'r')
	{
		if (fork() == 0)
		{
			dup2(fd[1], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			return -1;
		}
		close(fd[0]);
		return (fd[1]);
	}
	if (type == 'w')
	{
		if (fork() == 0)
		{
			dup2(fd[0], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			return -1;
		}
		close(fd[1]);
		return (fd[0]);
	}
	return -1;
}

/* #include <string.h>
int main()
{
	//int fd = open("texte", O_RDONLY);
	int fd = ft_popen("lss", (char *const[]){"ls", NULL}, 'r');

	char buf[1];
	while(read(fd, buf, 1))
		write(1, buf, 1);

	close(fd);
	return (0);
} */