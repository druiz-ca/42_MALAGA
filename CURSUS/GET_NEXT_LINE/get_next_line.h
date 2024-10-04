/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:06:07 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/03/29 11:40:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*ft_strjoin(char *buffer, char *buffer_aux);
char	*ft_strchr(char *buffer, char salto);
size_t	ft_strlen(char *cad);
char	*ft_leer(int fd, char *buffer);
char	*ft_linea(char *buffer);
char	*ft_resto_buffer(char *buffer);
char	*get_next_line(int fd);
char	*ft_substr(char *buffer, unsigned int inicio, size_t long_a_copiar);
char	*ft_free(char *cad);

#endif