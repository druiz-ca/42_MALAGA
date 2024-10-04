/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:51 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/10 17:22:27 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - BUSCA EL PRIMER CARACTER RECIBIDO EN LA CADENA
    - DEVUELVE UN PUNTERO APUNTANDO A LA POSICION DONDE LO ENCUENTRA
    - si no lo encuentra, devuelve NULL

// cuando es const char, el RETURN tiene que ser así, con (char*)cad
// sino, hay que poner const char al inicio de la función y a la variable
// del main donde se guarda el valor que retorna
- El resturn cad se tiene que castear a (char*)cad porque la función
  devuelve un puntero a char y cad es const char !!!
*/

#include "libft.h"

char	*ft_strchr(const char *cad, int c)
{
	while (*cad)
	{
		if (*cad == (char)c)
			return ((char *)cad);
		cad++;
	}
	if ((char)c == '\0')
		return ((char *)cad);
	return (0);
}
/* 
int main ()
{
    printf("%s\n", ft_strchr("manolo", 'l'));

    // Comprobación de la función real
    printf("%s\n", strchr("manolo", 'l'));
} */