/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 17:14:01 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_args_struct *args, int pipe_fd[2], char **envp)
{
	pid_t	pid;

	pid = fork(); // crea un proceso hijo
	if (pid == -1)
		ft_error(args, "fork");
	if (pid == 0)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1) // redirige la salida estandar al pipe
			ft_error(args, "dup2");
		close(pipe_fd[0]); // cierra el descriptor de lectura
		if (execve(args->path_cmd1, args->cmd1_matrix, envp) == -1) // ejecuta el comando
			ft_error(args, "execve");
	}
	else
	{
		close(pipe_fd[1]); // cierra el descriptor de escritura
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1) // redirige la entrada estandar al pipe
			ft_error(args, "dup2");
		waitpid(pid, NULL, 0); // espera a que el hijo termine
	}
}

void	ft_pipex(t_args_struct *args, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		ft_error(args, "pipe");
	if (dup2(args->fd1, STDIN_FILENO) == -1) // redirige la entrada estandar al archivo
		ft_error(args, "dup2");
	child_process(args, pipe_fd, envp);
	if (dup2(args->fd2, STDOUT_FILENO) == -1) // redirige la salida estandar al archivo
		ft_error(args, "dup2");
	pid = fork(); // crea un proceso hijo
	if (pid == -1)
		ft_error(args, "fork");
	if (pid == 0)
	{
		if (execve(args->path_cmd2, args->cmd2_matrix, envp) == -1) 
			ft_error(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0); // espera a que el hijo termine
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args_struct	*args;

	if (argc != 5)
	{
		write(1, "Error: Wrong number of arguments\n", 34);
		return (1);
	}
	else if (!envp || !envp[0]) // controla que exista la variable de entorno
	{
		write(1, "Error: no existe variable de entorno\n", 37);
		return (1);
	}
	else
	{
		args = malloc(sizeof(t_args_struct));
		if (!args)
			ft_error(args, "malloc");
		init_args(args, argv);
		checks(args, envp);
		open_infile(args);
		open_outfile(args);
		ft_pipex(args, envp);
		free_args_struct(args);
	}
}
