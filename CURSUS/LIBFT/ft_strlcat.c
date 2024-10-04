/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:56 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:15:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
- concatena 2 cadenas Y devuelve el tamaño de la cadena destino concatenda
- tiene en cuenta el tamaño del bufer de la cadena dest (el 20 char cad[20])
para no salir del bufer, x seguridad
strlcpy y strlcat copian y concatenan cadenas respectivamente, la diferencia 
es que strlcat devuelve el tamaño de la cadena que se intento crear, mientras
que strlcpy devuelve el tamaño de la cadena que se intento copiar.
- a diferencia de strcat, strlcat toma un tercer argumento que es el tamaño 
total del buffer de destino.
- el buffer es distinto de la cantidad de caracteres que tiene la cadena, 
el buffer es la cantidad de memoria que se le asigna a la variable, en este
caso, char cad[20], el buffer es de 20 bytes, pero la cadena tiene 5 caracter
- 1er WHILE: Si el tamaño del buffer de destino es menor o igual a la longitud 
de la cadena de destino, significa que no hay suficiente espacio en el buffer 
de destino para la cadena de origen. En este caso, la función devuelve la suma
de size y src_len, que es la longitud que tendría la cadena de destino si se 
pudiera concatenar completamente la cadena de origen. Esto es útil para el
lamador para saber cuánto espacio necesitaría para la concatenación completa.


ERRORES
// me fallaba aquí porque enviaba un CONST CHAR y recibia un CHAR
//size_t buferdest = sizeof(dest);
//printf("%zu\n", buferdest);
// size_t len = ft_strlen(dest);
     if (lendest > buferdest)
        return (len);
- Creo que mi libreria tiene que ir primero que la libreria de C
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *cad, size_t lendest)
{
	size_t	i;
	size_t	j;
	size_t	longdest;

	i = 0;
	j = 0;
	longdest = 0;
	while (dst[i] && i < lendest)
		i++;
	longdest = i;
	j = 0;
	while (cad[j] && i + 1 < lendest)
	{
		dst[i] = cad[j];
		i++;
		j++;
	}
	if (longdest < lendest)
		dst[i] = '\0';
	return (longdest + ft_strlen(cad));
}

/* int main ()
{   // el tamaño del bufer es el "10", es decir, la cant. de mem. de la 
//variable char
    char dest[16] = "pepe"; // Cuando se va a modificar la cadena se debe 
	//enviar asi
    printf("%zu\n", ft_strlcat(dest, "manolo", sizeof(dest)));
	printf("%s\n", dest);

    // Comprobación de la función real
    printf("%zu\n", strlcat(dest, "manolo", sizeof(dest)));
}
 */