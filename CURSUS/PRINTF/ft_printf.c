/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:04:53 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/11 16:53:26 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* 'x' = se espera que el argumento correspondiente sea un entero sin signo,
y se imprimirá como un número hexadecimal en minúsculas.
printf("%x\n", value); imprime el valor de value como un número 
hexadecimal. Dado que el valor de value es 255, y 255 es ff en 
hexadecimal, el programa imprime ff. 
- si le pongo el i++ en linea 64 no funciona...
*/

static int	ft_formato(va_list lista_arg, const char c)
{
	int	longitud;

	longitud = 0;
	if (c == 'c')
		longitud += ft_imprimir_caracter(va_arg(lista_arg, int));
	else if (c == 's')
		longitud += ft_imprimir_cadena(va_arg(lista_arg, char *));
	else if (c == 'p')
		longitud += ft_imprimir_ptr(va_arg(lista_arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		longitud += ft_imprimir_num(va_arg(lista_arg, int));
	else if (c == 'u')
		longitud += ft_imprimir_unsigned(va_arg(lista_arg, unsigned int));
	else if (c == 'x' || c == 'X')
		longitud += ft_imprimir_hex(va_arg(lista_arg, unsigned int), c);
	else
		longitud += ft_imprimir_caracter(c);
	return (longitud);
}

int	ft_imprimir_caracter(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		longitud;
	va_list	lista_arg;

	i = 0;
	longitud = 0;
	va_start(lista_arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			longitud += ft_formato(lista_arg, str[i]);
		}
		else
			longitud += ft_imprimir_caracter(str[i]);
		i++;
	}
	va_end(lista_arg);
	return (longitud);
}

int main()
{
	int x = 5;
	ft_printf("h %c %s %p %d\n", 'a', "pe", 0x7fff5fbff670, 6);
	ft_printf("%i %u %x %X %%\n", &x, 4, 255, 255);

}