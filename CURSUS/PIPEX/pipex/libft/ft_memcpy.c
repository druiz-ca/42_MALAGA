/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:38 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:16:55 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION:     
- copia n bytes de memoria de src a dest sin tener en cuanta el tamaño de las cad
- hay que controlar que no estén vacias las cadenas
- al ser void, hay que castearlo a char
- al recibir la n de tipo size_t, hay que declarar la i de tipo size_t
ERRORES
- tenía i <=n 
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *cad, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !cad)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)cad)[i];
		i++;
	}
	return (dest);
}
/* 
int main()
{
    char dest[20];
    printf("%s\n", ft_memcpy(dest, "manolo", 4));

    // Comprobación de la función real
    printf("%s\n", memcpy(dest, "manolo", 4));
} */