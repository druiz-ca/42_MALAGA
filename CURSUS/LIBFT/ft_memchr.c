/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:28 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:17:01 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
- Busca un carácter "c" durante los "n" números de caráctereña de la cadena "cad"
- la función devuelve un puntero a la ubicación del carácter,
- la diferencia entre memchr y strchr es que memchr busca en los primeros n bytes
 y strchr busca en toda la cadena
- Si lo encuentra, devuelve el puntero apuntado a la 1a ubicación de "c", 
	sino, NULL

// como el puntero CAD es VOID, hay que especificar que tipo usaremos
// void *cad = puntero genérico que sirve para apuntar a cualquier tipo de dato
// entre paréntesis (esto creo que se llama "cast"/"casting": conversiones)
// los punteros void no se pueden dereferenciar
// CAD + I = devuelve la pos. I de la cad

ERRORES
- habia puesto i <= n, y no i < n
*/
#include "libft.h"

void	*ft_memchr(const void *cad, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	car;

	str = (unsigned char *)cad;
	car = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == car)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
/* 
int main()
{
    printf("%s\n", ft_memchr("manolo", 'o', 5));
    // Comprobación de la función real
    printf("%s\n", memchr("manolo", 'o', 5));
} */