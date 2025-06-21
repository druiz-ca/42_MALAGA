#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <string.h>
#include <sys/wait.h>

void err(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int cd(char **argv)
{
    if (argv[2] != 0) // si tiene más de un argumento
    {
        err("error: cd: bad arguments\n");
        return 1;
    }
    chdir(argv[1]);
    return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
    if (has_pipe != 0)
    {
        dup2(fd[end], end);
        close(fd[0]);
        close(fd[1]);
	} 
}

int exec(char **argv, int i, char **envp)
{
    int has_pipe;
    int fd[2];
    int pid;
    int status;

    has_pipe = 0;
    if (argv[i] && strcmp(argv[i], "|") == 0)
        has_pipe = 1;
    if (has_pipe == 0 && strcmp(argv[0], "cd") == 0)
        return cd(argv);

    pipe(fd);
    pid = fork();

    if (pid == 0)
    {
        //argv[i] = NULL;
        set_pipe(has_pipe, fd, 1);
        if (execve(argv[0], argv, envp) == -1)
        {
            err("error: cannot execute ");
            err(argv[0]);
            err("\n");
            exit(1);
        }
    }
    else
    {
        set_pipe(has_pipe, fd, 0);
        waitpid(pid, &status, 0);
    }
    return 0;

}

int main(int argc, char **argv, char **envp)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = i;
        while (j < argc && strcmp(argv[j], ";") != 0 && strcmp(argv[j], "|") != 0)
            j++;
        if (j > i)
            exec(argv + i, j - i, envp);
        i = j + 1;
    }
    return 0;
}