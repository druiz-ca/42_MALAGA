/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:04:05 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/10/11 18:46:10 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
            exec_command(commands, shell, i);
        shell->fdin = shell->fdnextin;
        i++;
    }
}