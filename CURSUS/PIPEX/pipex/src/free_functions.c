/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 10:57:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*free_matrix(char **matrix, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

void	free_function(t_args_struct *args)
{
	int	i;

	i = 0;
	if (args->cmd1_matrix != NULL)
	{
		while (args->cmd1_matrix[i])
			i++;
		free_matrix(args->cmd1_matrix, i);
	}
	i = 0;
	if (args->cmd2_matrix != NULL)
	{
		while (args->cmd2_matrix[i])
			i++;
		free_matrix(args->cmd2_matrix, i);
	}
}

void	*free_args_struct(t_args_struct *args)
{
	if (args->cmd1)
		free(args->cmd1);
	if (args->cmd2)
		free(args->cmd2);
	if (args->path_cmd1)
		free(args->path_cmd1);
	if (args->path_cmd2)
		free(args->path_cmd2);
	free_function(args);
	if (args != NULL)
		free(args);
	return (NULL);
}
