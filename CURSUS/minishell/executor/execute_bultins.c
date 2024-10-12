/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bultins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:04:05 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/10/12 18:20:21 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*actualiza la variable de entorno OLDPWD*/
void    update_oldpwd(t_shell *shell, int i)
{
    if (shell->oldpwd != NULL && ft_strncmp(shell->env[i], "OLDPWD=", 7) == 0)
    {
        free(shell->env[i]);
        shell->env[i] = ft_strjoin("OLDPWD=", shell->oldpwd);
    }
    free(shell->oldpwd);
}

/* actualiza las variables de entorno */
void    reset_env(t_shell *shell, t_cmd **commands)
{
    int i;

    i = 0;
    
}

/* Comprueba si el comando es un builtin o un comando del sistema  (bin)*/
void    check_if_bultin(t_cmd **commands, t_shell *shell, int i)
{
    shell->g_status = 0;
    if (commands[i]->cmd && check_if_is_builtin(commands[i]->cmd) == 1)
        choose_builtin(shell, commands, i);
    else if (commands[i]->cmd)
        execute_bin_cmd(shell, commands, i);
}

/* Crea la tubería y guarda los fd en la estructura */
void    config_pipe(t_shell *shell)
{
    int fd[2];

    if (pipe(fd) == -1)
    {
        write(STDERR_FILENO, "pipe: error creating pipe\n", 27);
        shell->exec_signal = 1;
        shell->g_status = 1;
    }
    else
    {
        shell->fdnextin = fd[0];
        shell->fdout = fd[1];
    }
}

void    execute(t_cmd **commands, t_shell *shell)
{
    int i;

    i = 0;
    save_fds(shell);
    while (commands[i] != NULL)
    {
        shell->fdnextin = -1;
        if (commands[i + 1] != NULL)
            config_pipe(shell);
        else
            shell->fdout = STDOUT_FILENO;
        choose_redirections(commands[i]->incmd, shell);
        choose_redirections(commands[i]->outcmd, shell);
        if (commands[i]->cmd != NULL)
            check_if_builtin(commands, shell, i);
        shell->fdin = shell->fdnextin;
        i++;
    }
    reset_env(shell, commands);
    reset_redirections(shell);
}