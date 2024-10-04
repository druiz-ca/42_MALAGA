/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:06:14 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/20 10:20:09 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// si no se controla este null falla
// porque tiene que llevar parentesis?
// xq sin return falla??
// cuando casteo una variable en write pq no funciona
int	ft_imprimir_cadena(char *cad)
{
	int	longitud;

	longitud = 0;
	if (cad == NULL)
		return (ft_imprimir_cadena("(null)"));
	while (cad[longitud])
		longitud += ft_imprimir_caracter(cad[longitud]);
	return (longitud);
}

int	ft_imprimir_num(int n)
{
	int	longitud;

	longitud = 0;
	if (n == 0)
		longitud += ft_imprimir_caracter('0');
	if (n == -2147483648)
	{
		longitud += ft_imprimir_cadena("-2147483648");
		return (longitud);
	}
	if (n < 0)
	{
		longitud += ft_imprimir_caracter('-');
		n = -n;
	}
	if (n > 0)
		longitud += ft_imprimir_unsigned((unsigned int)n);
	return (longitud);
}

int	ft_imprimir_unsigned(unsigned int n)
{
	int	longitud;

	longitud = 0;
	if (n == 0)
		longitud += ft_imprimir_caracter('0');
	else
	{
		if (n / 10 != 0)
			ft_imprimir_unsigned(n / 10);
		ft_imprimir_caracter((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			longitud++;
		}
	}
	return (longitud);
}
