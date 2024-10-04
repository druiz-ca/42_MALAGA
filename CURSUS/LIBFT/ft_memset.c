/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:47 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:16:41 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION:
    - sirve para llenar un bloque de memoria con un valor "c", "n" veces
*/
// se me había olvidado inicializar la i en 0

#include "libft.h"

void	*ft_memset(void *cad, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)cad)[i] = c;
		i++;
	}
	return (cad);
}
/* 
int main ()
{ // como voy a modificar la cadena tengo que declararla así
    char cad[] = "donde esta pepe que no lo encuentro";
    // De esta forma se pasa el punt a otra pos. , no la 0
    printf("%s\n", ft_memset(cad + 4, '.', 5));

    // Comprobación de la función real
    printf("%s\n", memset(cad + 4, '.', 5));
} */