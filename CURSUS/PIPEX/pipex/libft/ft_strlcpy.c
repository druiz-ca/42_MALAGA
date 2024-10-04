/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:19:03 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:15:18 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    COPIA UNA CADENA A OTRA CONTEMPLANDO LAS MEDIDAS DE LAS 2 CADENAS 
    en vez de la strcpy normal que solo contempla la long de dest, 
    no la de origen para no rellenar bytes con 0 hasta llegar a rellenar la 
    long de destino
    - La funcion devuelve la long de la cadena origen, no la de destino 
    - hay que contemplar que los punteros no apunten a NULL

ERRORES
	- Tenía puesto si i <= long_dest
	- había puesto dest[i] = '\0'; fuera de la condicion if, por lo que se 
	aplicaba siempre!
	- no habia puesto long_dest - 1, es decir, que no copiaba el \0

DUDAS/PREGUNTAS

?? STRLCPY NO DEBERIA DEVOLVER LA CADENA, Y NO UN N'UMERO???
    - No, devuelve la long de la cadena origen mediante un strlen, y copia 
    la cadena
    a destino, pero como se envia x puntero no necesita devolverlo
?? Entonces, si usa STRLEN, no entiendo todo eso de que calcula el buffer 
y no la long

?? PORQUE ME COPIA LA CADENA MENOS 1 CARACTER
?? Si esta func necesita llamar a strlen, al entregar el ej. se incluye o no 
    // size_t almacena datos positivos enteros = typedef unsigned long
    // se usa para cosas que nunca usen negativos, por ejemplo, como cuando
    //usamos la i para recorrer un array, ya que no hay posicion -1
   // strlcpy(dest, cad, longitud_destino);
    //la sintaxis de strlcpy es CAD1 + CAD2 + LONGITUD DE LA CADENA DESTINO
    // strlcpy devuelve la medida de la cadena -1, es decir, solo el contenido
	
 */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *cad, size_t longitud)
{
	size_t	contador;

	contador = 0;
	if (longitud == 0)
		return (ft_strlen(cad));
	while (cad[contador] && contador < (longitud - 1))
	{
		dest[contador] = cad[contador];
		contador++;
	}
	dest[contador] = '\0';
	return (ft_strlen(cad));
}

/* int main ()
{
    char dest[7]; // 20 es el tama;o del buffer (memoria temporal)
    // sino pongo la medida de bufer exacta se vuelve loco=frase + 1 del NULL
    printf("%zu\n", ft_strlcpy(dest, "pepe", 4));

    // Comprobación de la función real
    printf("%zu\n", strlcpy(dest, "pepe", 4));
} */