/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:19:19 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:14:02 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
- BUSCA UNA SUB-CADENA DENTRO DE UNA CADENA DE TEXTO EXCLUYENDO EL \0
- Busca hasta n cantidad de caracteres
- DEVUELVE UN PUNTERO APUNTADO A LA POSICION DEL CARACTER DE LA PRIMERA APARICION
DE LA CADENA BUSCADA
- SI LA CAD QUE HAY QUE BUSCAR ESTA VACIA LA FUNCION DEVUELVE LA CAD1
- SI LA CAD QUE HAY QUE BUSCAR NO ESTA EN LA CAD1 DEVUELVE NULL
- SI LA CAD QUE HAY QUE BUSCAR ES MAYOR QUE LA CAD1 DEVUELVE NULL
- SI LA CAD QUE HAY QUE BUSCAR ES IGUAL QUE LA CAD1 DEVUELVE LA CAD1

// me obliga a usar i e j para conservar la pos. de la 1a letra
// ABAJO le tengo que decir j+1 para que compruebe si el siguiente es NULL
// esto se usa para convertir la variable void a char

ERRORES
- 
*/
#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*find)
		return ((char *)str);
	i = ft_strlen(find);
	while (ft_strncmp(&str[j], find, i) != 0)
	{
		if (!str[j] || j >= (len - i))
			return (NULL);
		++j;
	}
	if (i > len)
		return (NULL);
	return ((char *)(&str[j]));
}

/* int main ()
{
    printf("%s\n", ft_strnstr("donde esta pepe, no lo encuentro", "pepe", 40));

    // Comprobación de la función real
    printf("%s\n", strnstr("donde esta pepe, no lo encuentro", "pepe", 40));
} */