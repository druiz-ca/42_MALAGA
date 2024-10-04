/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:06:57 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/24 17:17:01 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_longitud_hex(unsigned int num)
{
	int	longitud;

	longitud = 0;
	while (num != 0)
	{
		longitud++;
		num = num / 16;
	}
	return (longitud);
}

void	ft_buscar_hex(unsigned int num, const char palabra)
{
	int				i;
	char			result[64];
	unsigned int	resto;

	i = 0;
	while (num != 0)
	{
		resto = num % 16;
		if (resto < 10)
			result[i++] = resto + '0';
		else
		{
			if (palabra == 'x')
				result[i++] = resto - 10 + 'a';
			else if (palabra == 'X')
				result[i++] = resto - 10 + 'A';
		}
		num /= 16;
	}
	while (--i >= 0)
		ft_imprimir_caracter(result[i]);
}

int	ft_imprimir_hex(unsigned int num, const char palabra)
{
	if (num == 0)
		return (ft_imprimir_caracter('0'));
	else
		ft_buscar_hex(num, palabra);
	return (ft_longitud_hex(num));
}
