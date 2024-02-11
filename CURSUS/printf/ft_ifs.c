/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:19:41 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/09 12:13:35 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
WRITE
- se puede ir recorriendo la cadena e ir imprimiendo cada caracter
	while (*c)
		write(1, c++, 1);
- 0 se puede calcular la long de la cad y tan solo especificar la long
	(write(1, cad, ft_strlen(cad))
	- de esta forma se ahorra la linea del while!!!
*/
void	ft_if_u(va_list lista_argumentos)
{
	unsigned int	num3;
	char			*cad3;

	num3 = va_arg(lista_argumentos, unsigned int);
	cad3 = ft_uitoa(num3);
	while (*cad3)
		write(1, cad3++, 1);
	return ;
}

void	ft_if_d_i(va_list lista_argumentos)
{
	int		num2;
	char	*cad2;

	num2 = va_arg(lista_argumentos, int);
	cad2 = ft_itoa(num2);
	while (*cad2)
		write(1, cad2++, 1);
	return ;
}

void	ft_if_p(va_list lista_argumentos)
{
	void	*ptr;
	int		len;
	char	buffer[20];

	ptr = va_arg(lista_argumentos, void *);
	len = sprintf(buffer, "%p", ptr);
	write(1, buffer, len);
	return ;
}

void	ft_if_s(va_list lista_argumentos)
{
	char	*cad;

	cad = va_arg(lista_argumentos, char *);
	while (*cad)
		write(1, cad++, 1);
	return ;
}

void	ft_if_c(va_list lista_argumentos)
{
	int	c;

	c = va_arg(lista_argumentos, int);
	write(1, &c, 1);
	return ;
}
/*el p = tiene que calcular la long de la dir de mem del ptr*/
