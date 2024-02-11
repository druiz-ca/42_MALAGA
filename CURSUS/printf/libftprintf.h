/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/02 13:27:30 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
#define LIBFT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char    *ft_itoa(int num);
char    *ft_uitoa(unsigned int num);
char    *ft_hexitoa(unsigned int num);
void    ft_if_u(va_list lista_argumentos);
void    ft_if_d_i(va_list lista_argumentos);
void    ft_if_p(va_list lista_argumentos);
void    ft_if_s(va_list lista_argumentos);
void    ft_if_c(va_list lista_argumentos);
void    ft_if_x(const char *contenido, int i, va_list lista_argumentos);

#endif