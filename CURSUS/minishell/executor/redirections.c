/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:21:49 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/10/11 18:46:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Guarda los descriptores de archivo acuales de entrada y salida estándar */
void    save_fds(t_shell *shell)
{
    shell->exec_signal = 0;
    shell->infile = dup(STDIN_FILENO);
    shell->outfile = dup(STDOUT_FILENO);
}

void    choose_redirections(char **redirections, t_shell *shell)
{
    
}