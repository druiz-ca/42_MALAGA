/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:42 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:16:45 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION:
- copia de la cad en dest n números de carácteres
- tiene en cuenta la long de las cad, a diferencia de memcpy
- se usa const cuando no se va a modificar esa variable
- hay que controlar que las cadenas no sean igual a NULL
- unsigned char se usa para que no se pueda modificar el valor de la variable
  no destructiva
- Comprobamos si dst - src < len, si es así, copiamos de derecha a izquierda, 
sino de izquierda a derecha
- Al castear el punero a size_t podemos hacer la comparación
- Solo escribimos del revés si es mayor len que la diferencia entre dst y src
*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/* 
int main ()
{
    char dest[20];
    printf("%s\n", ft_memmove(dest, "manolo", 4));

    // Comprobación de la función real
    printf("%s\n", memmove(dest, "manolo", 4));
} */