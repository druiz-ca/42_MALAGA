/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:03 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/07 13:04:00 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
// falta que vaya sumando la longitud de lo que imprime
//35 - casteamos el int que nos devuelve va_arg a char
//43 - si pongo el ++ en el write, me imprime el primer caracter
//45 - no me imprime el primer caracter ???

static void	ft_comprobar(const char *contenido, int i, va_list lista_argumentos)
{
	while (contenido[i])
	{
		if (contenido[i] == 'c')
			ft_if_c(lista_argumentos);
		if (contenido[i] == 's')
			ft_if_s(lista_argumentos);
		if (contenido[i] == 'p')
			ft_if_p(lista_argumentos);
		if (contenido[i] == 'd' || contenido[i] == 'i')
			ft_if_d_i(lista_argumentos);
		if (contenido[i] == 'u')
			ft_if_u(lista_argumentos);
		if (contenido[i] == 'x' || contenido[i] == 'X')
			ft_if_x(contenido, i, lista_argumentos);
		else if (contenido[i] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		i++;
	}
	return ;
}

int	ft_printf(const	char *contenido, ...)
{
	va_list	lista_argumentos;
	int		longitud;
	int		i;

	i = 0;
	longitud = 0;
	va_start(lista_argumentos, contenido);
	while (contenido[i])
	{
		if (contenido[i] == '%')
		{
			i++;
			ft_comprobar(contenido, i, lista_argumentos);
		}
		else
			write(1, &contenido[i], 1);
		i++;
	}
	va_end(lista_argumentos);
	return (longitud);
}
// En el sistema numérico decimal (base 10) que usamos normalmente, 
//tenemos 10 dígitos: del 0 al 9. En el sistema hexadecimal, tenemos 16 
//dígitos: del 0 al 9, seguidos de las letras 'a' hasta 'f' que representan
//los valores del 10 al 15.
/* int main()
{
	int x = 5;
    ft_printf("hola %c %s %i %d %p %u %x %%", 'a', "pepe", -15, -16, &x, 4, 15);
} */