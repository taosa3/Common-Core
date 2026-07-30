#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int    picoshell(char **cmds[])
{
    int status;
    int i = 0;
    int ret = 0;
    int fd[2];
    pid_t pid;
    int in_file = 0;

    if (!cmds || !cmds[0])
        return 1;
    while(cmds[i])
    {
        if (cmds[i + 1] && pipe(fd) < 0)
            return 1;
        if ((pid = fork()) < 0)
        {
            if (cmds[i + 1])
            {
                close(fd[0]);
                close(fd[1]);
            }
            if (in_file != 0)
                close(in_file);
            return 1;
        }
        if (pid == 0)
        {
            if (in_file != 0)
            {
                if (dup2(in_file, STDIN_FILENO) < 0)
                    exit(1);
                close(in_file);
            }
            if (cmds[i + 1])
            {
                if (dup2(fd[1], STDOUT_FILENO) < 0)
                    exit(1);
                close(fd[1]);
                close(fd[0]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        if (in_file != 0)
            close(in_file);
        if (cmds[i + 1])
        {
            close(fd[1]);
            in_file = fd[0];
        }
        i++;
    }
    while(wait(&status) > 0)
        if(!WIFEXITED(status) || WEXITSTATUS(status))
            ret = 1;
    return ret;
}

#include <stdio.h>
int main(void)
{
    write(1, "Test picoshell_short\n", 21);
    // char *cmd1[] = {"/bin/ls", "-la", NULL};
    char *cmd1[] = {"/bin/ls", NULL};
    char *cmd2[] = {"/usr/bin/grep", "picoshell", NULL};
    char **cmds[] = {cmd1, cmd2, NULL};

    int result = picoshell(cmds);
    printf("picoshell returned %d\n", result);

    return 0;
}