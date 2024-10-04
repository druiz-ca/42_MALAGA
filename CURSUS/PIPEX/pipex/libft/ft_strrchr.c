/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:19:23 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:14:54 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
- BUSCA LA ULTIMA COINCIDENCIA DEL CARACTER RECIBIDO EN LA CADENA
el return es s + i, es decir, devuelve un puntero que apunta a la posición donde
encuentra el carácter
- DEVUELVE UN PUNTERO APUNTANDO A LA POSICION DONDE LO ENCUENTRA
- DEVUELVE NULL SI NO LO ENCUENTRA
- LA CLAVE ESTA EN EMPEZAR A CONTAR DESDE EL FINAL YA QUE PIDE LA ULTIMA LETRA

// como enviamos un CONST CHAR, debe recibir también como CONST CHAR
// había puesto size_t pero daba error pq es un caracter
// se pueden hacer operaciones aquí mismo
// REPASAR ESTA FORMA DE RETURN con &
ERRORES

*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* int main ()
{
    // Mi función
    printf("%s\n", ft_strrchr("malnolo", 'l'));
    
    // Comprobación de la función real
    printf("%s\n", strrchr("malnolo", 'l'));
} */