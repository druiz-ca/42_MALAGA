/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:19:08 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:14:28 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - 
*/
// devuelve el size_t en vez del int x seguridad
#include "libft.h"

size_t	ft_strlen(const char *cad)
{
	size_t	i;

	i = 0;
	while (cad[i] != '\0')
		i++;
	return (i);
}
/* 
int main ()
{
    printf("%i\n", ft_strlen("cadena"));

    // Comprobación de la función real
    printf("%i\n", strlen("cadena"));
}
 */