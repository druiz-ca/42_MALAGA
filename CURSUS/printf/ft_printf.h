/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/07 11:50:17 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h> // la libreria de va_arg
# include <stdint.h>
# include <inttypes.h>

char	*ft_itoa(int num);
char	*ft_uitoa(unsigned int num);
char	*ft_hexitoa(unsigned int num);
void	ft_if_u(va_list lista_argumentos);
void	ft_if_d_i(va_list lista_argumentos);
void	ft_if_p(va_list lista_argumentos);
void	ft_if_s(va_list lista_argumentos);
void	ft_if_c(va_list lista_argumentos);
void	ft_if_x(const char *contenido, int i, va_list lista_argumentos);

#endif