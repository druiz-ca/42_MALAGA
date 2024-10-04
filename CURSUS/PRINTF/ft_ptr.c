/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:07:22 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/19 10:39:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* 0x para indicar que un número está en base hexadecimal. ejemplo,
 el número 0x10 es 16 en decimal. 0x7fff5fbff670 es una dirección de 
 memoria en hexadecimal. */
static int	ft_longitud_ptr(unsigned long long ptr)
{
	int	longitud;

	longitud = 0;
	while (ptr > 0)
	{
		longitud++;
		ptr /= 16;
	}
	return (longitud);
}

static void	ft_imprimir_puntero(unsigned long long ptr)
{
	int					i;
	char				resultado[64];
	unsigned long long	resto;

	i = 0;
	while (ptr != 0)
	{
		resto = ptr % 16;
		if (resto < 10)
			resultado[i++] = resto + '0';
		else
			resultado[i++] = resto - 10 + 'a';
		ptr /= 16;
	}
	while (--i >= 0)
		ft_imprimir_caracter(resultado[i]);
}

int	ft_imprimir_ptr(unsigned long long ptr)
{
	int	longitud;

	longitud = 0;
	longitud += ft_imprimir_cadena("0x");
	if (ptr == 0)
		longitud += ft_imprimir_caracter('0');
	else
	{
		ft_imprimir_puntero(ptr);
		longitud += ft_longitud_ptr(ptr);
	}
	return (longitud);
}
