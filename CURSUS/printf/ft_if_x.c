/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:28:30 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/08 10:23:00 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_x(const char *contenido, int i, va_list lista_argumentos)
{
	unsigned int	num4;
	char			*cad4;

	num4 = va_arg(lista_argumentos, unsigned int);
	cad4 = ft_hexitoa(num4);
	if (contenido[i] == 'X')
	{
		while (*cad4)
		{
			if (*cad4 >= 'a' && *cad4 <= 'f')
				*cad4 -= 32;
			write(1, cad4++, 1);
		}
	}
	else if (contenido[i] == 'x')
	{
		while (*cad4)
			write(1, cad4++, 1);
	}
	return ;
}
