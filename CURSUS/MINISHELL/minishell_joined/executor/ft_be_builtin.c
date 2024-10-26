/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_be_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:05:10 by sternero          #+#    #+#             */
/*   Updated: 2024/10/26 12:16:46 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_is_builtin(t_var *cmd, t_minishell *minishell)
{// ya viene el comando solo, no hay que sacarlo de la estructura
	if (cmd == NULL || cmd->value == NULL)
	{
		ft_printf(BDRED "Error: command not allowed\n"RESET);
		return (FAILURE);
	}
	if (ft_strcmp(cmd->value, "cd") == 0)
		ft_cd(cmd, minishell); // en el mio mandaba el comando y la estructura ??
	else if (ft_strcmp(cmd->value, "pwd") == 0)
		ft_pwd(cmd);
	else if (ft_strcmp(cmd->value, "clear") == 0)
		ft_clear(cmd);
	else if (ft_strcmp(cmd->value, "exit") == 0)
		ft_exit(cmd, minishell);
	else if (ft_strcmp(cmd->value, "env") == 0) //print_env_env
		ft_print_env(minishell);
	else if (ft_strcmp(cmd->value, "echo") == 0)
		ft_echo_cmd(cmd, minishell);
	else if (ft_strcmp(cmd->value, "unset") == 0) //delete_env_unset
		ft_delete_env_unset(cmd, minishell);
	else if (ft_strcmp(cmd->value, "export") == 0)//update_env_export
		ft_update_env_export(cmd, minishell);
	return (0);
}

int ft_clear(t_var *cmd)
{
	if (cmd->left == NULL)
		ft_printf("\033[H\033[J");
	else
	{
		ft_printf(BDRED"Error : To many arguments for 'clear' command\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

/* La función ft_is_builtin() verifica si el comando ingresado por el usuario 
	es un comando integrado en el shell. Si el comando es un comando integrado, 
	se llama a la función correspondiente. Si el comando no es un comando 
	integrado, se imprime un mensaje de error. */

/* La función ft_clear() se encarga de limpiar la pantalla. Si el comando
	'clear' no tiene argumentos, se limpia la pantalla. Si el comando 'clear'
	tiene argumentos, se imprime un mensaje de error. */

/* The ft_is_builtin() function checks if the command entered by the user is a
	builtin command in the shell. If the command is a builtin command, the
	corresponding function is called. If the command is not a builtin command, 
	an error message is printed. */

/* The ft_clear() function is responsible for clearing the screen. If the 
	'clear' command has no arguments, the screen is cleared. If the 'clear' 
	command has arguments, an error message is printed. */