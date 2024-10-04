/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:19:32 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/10/02 19:17:34 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
// pwd = printf working directory

void	renew_path(t_shell *shell)
{
	char cwd[PATH_MAX];
	int i;

	i = 0;
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		write_cd_err(shell);
		shell->g_status = 1;
	}
	while (shell->env[i] != NULL)
	{
		if (strncmp(shell->env[i], "PWD", 4) == 0)
		{
			free(shell->env[i]);
			shell->env[i] = ft_strjoin("PWD=", cwd);
			if (shell->env[i] == NULL)
			{
				shell->g_status = 1;
				return ;
			}
			return ;
		}
		i++;
	}
}

void	back_pwd(t_shell *shell)
{
	char *back_path;

	back_path = ft_get_env("OLDPWD", shell->env);
	if (back_path == NULL)
	{
		write(STDERR_FILENO, "cd: OLDPWD not set\n", 20);
		shell->g_status = 1;
		return ;
	}
	if (chdir(back_path) == -1)
	{
		write(STDERR_FILENO, "cd: no such file or directory: ", 31);
		write(STDERR_FILENO, back_path, ft_strlen(back_path));
		write(STDERR_FILENO, "\n", 2);
		shell->g_status = 1;
	}
	write(shell->fdout, back_path, ft_strlen(back_path));
	write(shell->fdout, "\n", 2);
	free(back_path);	
}

void	exec_cd_home(t_shell *shell)
{
	char *home_path;

	home_path = ft_get_environment("HOME", shell->env);
	if (home_path == NULL)
		return ;
	if(chdir(home_path) == -1)
	{
		write(STDERR_FILENO, "cd: no such file or directory: ", 29);
		write(STDERR_FILENO, home_path, ft_strlen(home_path));
		write(STDERR_FILENO, "\n", 2);
		shell->g_status = 1;
	}
	free(home_path);
}

char	*ft_get_environment(char *str_pwd, char **env_paths)
{
	int i;
	int j;
	int k;
	char *full_path;
	
	i = 0;
	j = 0;
	k = 0;
	while (env_paths[i] != NULL)
	{
		if (ft_strncmp(env_paths[i], str_pwd, 3) == 0)
		{
			full_path = ft_strdup(env_paths[i] + 4);
			if (full_path == NULL)
				return (NULL);
			return (full_path);
		}
		i++;
	}
	return (NULL);
}

void	ft_cd(char **full_command, t_shell *shell)
{
	if (full_command[1] != NULL)
	{
		write(STDERR_FILENO, "cd: too many arguments", 23);
		shell->g_status = 1;
		return ;
	}
	shell->oldpwd = ft_get_environment("PWD", shell->env);
	if (full_command[0][0] == NULL)
		exec_cd_home(shell);
	else if (full_command[0][0] == '~')
		exec_cd_home(shell);
	else if (full_command[0][0] == '-')
		exec_backpwd(shell);
	if (shell->g_status == 1)
	{
		free(shell->oldpwd);
		shell->oldpwd = NULL;
	}
	else
		renew_path(shell);
}