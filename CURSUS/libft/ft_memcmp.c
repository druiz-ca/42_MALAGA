/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:34 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:16:56 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION:     
- Compara los primeros n bytes de las cadenas de caracteres s1 y s2. Devuelve
un entero menor, igual o mayor que cero si s1 es, respectivamente, menor, igual
 o mayor que s2. 

DESARROLLO
- Se declaran dos punteros que apuntan a las cadenas de caracteres
para evigtar tener que estar casteando durante toda la función.
- Se recorre la cadena de caracteres hasta que se llegue al final o hasta que
se encuentre una diferencia entre los caracteres de las cadenas de caracteres.
- Se devuelve la diferencia entre los caracteres de las cadenas de caracteres.
- Si no se encuentra ninguna diferencia, se devuelve 0.

ERRORES
- Habia puesto i<n en vez de i<=n, por lo que no comparaba el ultimo caracter
- había puesto n >= 0 en vez de n > 0, por lo que comparaba un caracter de más

TIPS
- a la vez que se contempla la variable n en el while se puede decir que una 
vez pase x ahí directamente le reste 1 para ahorrar una linea de código
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

/* int main()
{
    printf("%i\n", ft_memcmp("pepe", "pepe", 3));

    // Comprobación de la función real
    printf("%i\n", memcmp("pepe", "pepe", 3));
}
 */