/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:28:10 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:19:18 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCION
- C ALLOC : Clear allocation
- Toma 2 argumentos: el nº de elementos a asignar y el tamaño de cada elemento
- Asigna espacio para una matriz de x elementos inicializados en 0
// el int lleva tantos * como el el puntero donde se almacenará el res.
// el SIZEOF devuelve el tamaño en bytes (un int ocupa 2 bytes)
// el segundo int lleva 1* menos que el 1º del malloc

ERRORES
- 

*/
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

/* int main()
{
    int i = 0;
    size_t n = 20;   
    size_t medida = 10;          // el calloc usa "," en vez de "*"
    int *cad = (int*)ft_calloc(n, medida); //casteamos el void que devuelve
    if (cad == NULL) // no es *cad (lo que contiene la pos 1 de la cad)
    // Comprobador de que se ha podido asginar la memoria
        printf("%s", "no se ha podido imprimir");
    else
        printf("%i\n", cad[0]);
    
    //función de prueba original
    int *cad2 = (int*)calloc(n, medida);
    printf("%d\n", cad2[0]);
} */