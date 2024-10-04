/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:07:51 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/11 16:46:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_imprimir_caracter(int caracter);
int	ft_imprimir_cadena(char *str);
int	ft_imprimir_num(int n);
int	ft_imprimir_unsigned(unsigned int n);
int	ft_imprimir_ptr(unsigned long long ptr);
int	ft_imprimir_hex(unsigned int num, const char palabra);

#endif