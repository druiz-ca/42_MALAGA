/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:03 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/09 13:26:27 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//la var ... indica que la variable contenido puede contener varios argumentos
// se usa va_list(LISTA VARIABLE) para recorrer los argumentos
//35 - casteamos el int que nos devuelve va_arg a char
//43 - si pongo el ++ en el write, me imprime el primer caracter
//45 - no me imprime el primer caracter ???

static void	ft_formato(const char *contenido, int i, va_list lista_argumentos)
{
	while (contenido[i])
	{
		if (contenido[i] == 'c')
			ft_if_c(lista_argumentos);
		if (contenido[i] == 's')
			ft_if_s(lista_argumentos);
		if (contenido[i] == 'p')
			ft_if_p(lista_argumentos);
		if (contenido[i] == 'd')
			ft_if_d_i(lista_argumentos);
		if (contenido[i] == 'i')
			ft_if_d_i(lista_argumentos);
		if (contenido[i] == 'u')
			ft_if_u(lista_argumentos);
		if (contenido[i] == 'x' || contenido[i] == 'X')
			ft_if_x(contenido, i, lista_argumentos);
		if (contenido[i] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		else
			break ;
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
			ft_formato(contenido, i, lista_argumentos);
			longitud++;
		}
		else
			longitud += write(1, &contenido[i], 1);
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
	ft_printf("h %c %s %p %d %i %u %x %X %%\n", 'a', "pe", 5, 6, &x, 4, 1, 1);
} */