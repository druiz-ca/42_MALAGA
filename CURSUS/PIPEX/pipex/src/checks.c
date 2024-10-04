/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 17:42:29 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// une el comando con el path de la variable de entorno (envp)
char	*join_command(char *cmd, char *envp)
{
	char	*str;
	char	**path_matrix;
	int		i;

	i = 0;
	str = ft_substr(envp, 5, ft_strlen(envp)); // quita el "PATH=" del principio
	path_matrix = ft_split(str, ':'); // separa el path cuando hay un : en un array de strings
	free(str);
	while (path_matrix[i] != NULL)
	{ // recorre el array de strings y une el comando con cada path en str
		str = ft_strjoin(path_matrix[i], cmd);
		if (access(str, F_OK | X_OK) == 0) // verifica si el archivo existe y tiene permisos de ejecucion
			break ;
		free(str);
		str = NULL;
		i++;
	}
	while (path_matrix[i] != NULL) 
		i++;
	free_matrix(path_matrix, i);
	return (str);
}

void	check_infile(t_args_struct *args)
{
	if (access(args->file1, F_OK) != 0) // verifica si el archivo existe
	{
		ft_putstr_fd("Error: File 1 does not exist\n", 2);
		free_args_struct(args);
		exit(1);
	}
	if (access(args->file1, R_OK) != 0) // verifica si el archivo tiene permisos de lectura
	{
		ft_putstr_fd("Error: File 1 permissions denied\n", 2);
		free_args_struct(args);
		exit(5);
	}
}

void	checks(t_args_struct *args, char **envp)
{
	int	i;

	i = 0;
	check_infile(args);
	while (ft_strncmp(envp[i], "PATH=", 5) != 0) // busca la la linea que contiene PATH en envp
		i++;
	args->path_cmd1 = join_command(args->cmd1, envp[i]); // une el comando con el path
	if (args->path_cmd1 == NULL)
	{
		ft_printf("Command not found\n");
		free_args_struct(args);
		exit(127);
	}
	args->path_cmd2 = join_command(args->cmd2, envp[i]);
	if (args->path_cmd2 == NULL)
	{
		ft_putstr_fd("Error: Command not found\n", 2);
		free_args_struct(args);
		exit(127);
	}
}
