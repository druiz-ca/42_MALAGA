#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int execve(char **argv, int i, char **envp)
{
    int fd[2];
    int pid;
    int status;

    if (strcmp(argv[i], "|") != 0 && strcmp(argv[0], "cd") == 0)
    {
        if (argv[2] != 0)
        {
            write(2, "error: cd: bad arguments\n", 26);
            return (1);
        }
        chdir(argv[1]);
        return (0);
    }
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        if (strcmp(argv[i], "|") == 0)
        {
            dup2(fd[1], 1);
            close(fd[0]);
            close(fd[1]);
        }
        if (execve(argv[0], argv, envp) == -1)
        {
            write(2, "error: cannot execute ", 22);
            write(2, argv[0], strlen(argv[0]));
            write(2, "\n", 1);
            exit(1);
        }
    }
    else
    {
        if (strcmp(argv[i], "|") == 0)
        {
            dup2(fd[1], 1);
            close(fd[0]);
            close(fd[1]);
        }
        waitpid(pid, &status, 0);
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    int i = 1;
    int j;

    while (i < argc)
    {
        j = i;
        while (j < argc && strcmp(argv[j], ";") != 0 && strcmp(argv[j], "|") != 0)
            j++;
        if (j > i)
            execve(argv + i, j - i, envp);
        i = j + 1;
    }
    return (0);
}