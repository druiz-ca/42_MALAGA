/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/14 13:31:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "PRINTF/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_args_struct
{
	char	*cmd1;
	char	*cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
	char	**cmd1_matrix;
	char	**cmd2_matrix;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
}	t_args_struct;

/* Checks */
char	*join_command(char *cmd, char *envp);
void	check_infile(t_args_struct *args);
void	checks(t_args_struct *args, char **envp);

/* Free Functions */
void	*free_args_struct(t_args_struct *args);
void	*free_matrix(char **matrix, int cont);
void	free_function(t_args_struct *args);

/* Utils */
void	initialize_struct(t_args_struct *args);
void	init_args(t_args_struct *args, char **argv);
void	open_infile(t_args_struct *args);
void	open_outfile(t_args_struct *args);
void	ft_error(t_args_struct *args, char *error);

#endif