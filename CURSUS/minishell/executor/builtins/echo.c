/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:15:57 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/10/02 19:17:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Imprime en stdout los argumentos que recibe */

void echo(char **args, t_shell *shell)
{
    int i;
    int j;
    int new_line;

    i = 0;
    j = 0;
    new_line = 1;
    if (args[0][0] == '-' && args[1] == 'n')
        i += 2;
    else
        return ;
    if (args[0][i] != NULL)
        return ;
    new_line = 0;
    i++;
    while (args[i])
    {
        write(shell->fdout, )
        i++;
    }
    if (new_line)
        write(shell->fdout, "\n", 1);
}