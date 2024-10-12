/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:46:06 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/10/12 12:16:01 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void apply_heredoc(char *delimiter, t_shell *shell)
{
    int fdpipe[2];
    char *line;

    if(pipe(fdpipe) == -1)
    {
        write(STDERR_FILENO, "pipe: error creating pipe\n", 27);
        shell->exec_signal = 1;
        shell->g_status = 1;
    }
    while (1)
    {
        ft_putstr_fd("> ", 1);
        line = get_next_line(STDIN_FILENO);
        if (!line || ft_strcmp(line, delimiter) == 0)
            break ;
    }
    close(fdpipe[1]);
}