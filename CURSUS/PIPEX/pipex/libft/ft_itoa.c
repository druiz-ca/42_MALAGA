/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:45:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/11 18:56:26 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCION
    - Es un putchar en realidad, está el revés, recibe un int y devuelve una cad
- itoa si o si tiene que revertir el orden de los caracteres

// no se puede usar recursividad pq borra la mem cada vez q la llama
62 - 12 pq es el maximo de digitos que puede tener un int + el signo
//voy borrandolo de atras para adelante
// Ahora hay que invertir la cadena
// recorro la cad para tener la longitud
// resto 1 para que no cuente el \0
// mientras no se crucen en el medio
//intercambio el primer y ultimo valor, el segundo y penultimo
//avanzo en la cadena
//retrocedo en la cadena
//CAD[i++] = usa el i con su valor actual y luego lo incrementa
Cuando se declara un char se debe inicializar en '\0', y un puntero a NULL

ERRORES
- Fallaba por no ser long int, al ser int se desbordaba

*/
#include "libft.h"

static char	*ft_newarray(char *x, unsigned int num, long int len)
{
	while (num > 0)
	{
		x[len--] = (num % 10) + 48;
		num = num / 10;
	}
	return (x);
}

static long int	ft_longitud(int n)
{
	int	longitud;

	longitud = 0;
	if (n <= 0)
		longitud = 1;
	while (n != 0)
	{
		longitud++;
		n = n / 10;
	}
	return (longitud);
}

char	*ft_itoa(int n)
{
	char			*cad;
	int				len;
	unsigned int	num;
	int				operador;

	operador = 1;
	len = ft_longitud(n);
	cad = (char *)malloc(sizeof(char) * (len + 1));
	if (!(cad))
		return (NULL);
	cad[len--] = '\0';
	if (n == 0)
		cad[0] = '0';
	if (n < 0)
	{
		operador *= -1;
		num = n * -1;
		cad[0] = '-';
	}
	else
		num = n;
	cad = ft_newarray(cad, num, len);
	return (cad);
}

/* int main()
{
    printf("%s\n", ft_itoa(-123456789));
    printf("%s\n", ft_itoa(123456789));
	printf("%s\n", ft_itoa(0));

} */