/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 17:40:57 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_error(t_args_struct *args, char *error)
{
	perror(error);
	free_args_struct(args);
	exit(EXIT_FAILURE);
}

void	initialize_struct(t_args_struct *args)
{
	args->cmd1 = NULL;
	args->cmd2 = NULL;
	args->path_cmd1 = NULL;
	args->path_cmd2 = NULL;
	args->cmd1_matrix = NULL;
	args->cmd2_matrix = NULL;
	args->file1 = NULL;
	args->file2 = NULL;
	args->fd1 = 0;
	args->fd2 = 0;
}
// relleno la estructura con los argumentos pasados por el usuario (procesados)
void	init_args(t_args_struct *args, char **argv)
{
	int	i;

	i = 1;
	initialize_struct(args);
	if (argv[i][0] == '\0')
		ft_error(args, "Invalid command"); // si el argumento es un string vacio
	args->file1 = argv[i++];
	if (argv[i][0] == '\0')
		ft_error(args, "Invalid command"); // si el argumento es un string vacio
	args->cmd1_matrix = ft_split(argv[i++], ' ');
	if (!args->cmd1_matrix || args->cmd1_matrix[0][0] == '\0') // si el argumento es un string vacio
		ft_error(args, "ft_split");
	args->cmd1 = ft_strjoin("/", args->cmd1_matrix[0]); // agrega un '/' al principio del comando
	if (!args->cmd1)									// para despues añadirlo al path
		ft_error(args, "ft_strjoin");
	if (argv[i][0] == '\0')
		ft_error(args, "Invalid command"); // si el argumento es un string vacio
	args->cmd2_matrix = ft_split(argv[i++], ' ');
	if (!args->cmd2_matrix || args->cmd2_matrix[0][0] == '\0') // si el argumento es un string vacio
		ft_error(args, "ft_split");
	args->cmd2 = ft_strjoin("/", args->cmd2_matrix[0]);
	if (!args->cmd2)
		ft_error(args, "ft_strjoin");
	args->file2 = argv[i];
}

void	open_infile(t_args_struct *args)
{
	args->fd1 = open(args->file1, O_RDONLY);
	if (args->fd1 < 0)
		ft_error(args, "open");
}

void	open_outfile(t_args_struct *args)
{
	if (access(args->file2, F_OK) != 0) // si el archivo no existe lo crea
	{
		args->fd2 = open(args->file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (args->fd2 < 0)
			ft_error(args, "open");
	}
	else // si el archivo ya existe lo trunca
	{
		args->fd2 = open(args->file2, O_WRONLY | O_TRUNC);
		if (args->fd2 < 0)
			ft_error(args, "open");
	}
}
