/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:00:32 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:15:54 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCION
    - Reserva espacio de memoria para  una copia de CAD usando malloc
	- el dup significa duplicado
    - DEbe liberar el almacenacenamiento
    - Devuelve un puntero, sino ha podido reservar la mem devuelve NULL
	La función asigna memoria para una nueva cadena que tiene la misma longitud
	que src más uno para el carácter nulo al final. Si la asignación de memoria
	es exitosa, copia src en la nueva cadena con strcpy y devuelve un puntero a
	la nueva cadena. Si la asignación de memoria falla, malloc devuelve NULL, y
	ft_strdup también devuelve NULL en ese caso.
// nueva_cad[i] = '\0'; funciona tanto si lo pongo como sino ?
// daba error x poner cad* !!!

ERRORES
- no había calculado el malloc con el +1 del \0
- no había puesto el free
- no había puesto el return NULL del malloc
- cuando llamo a las librerias de C desde mi propia libreria, no hace falta
  llamarlas en cada archivo
- Estaba haciendo el free antes del return
- Estaba haciendo en malloc sizeof(cad) y aqui no se hace REPASAR!!!!
*/

#include "libft.h"

char	*ft_strdup(const char *cad)
{
	size_t	n;
	size_t	i;
	char	*nueva_cad;

	n = ft_strlen(cad);
	nueva_cad = (char *)malloc(n + 1);
	if (nueva_cad == NULL)
		return (NULL);
	i = 0;
	while (cad[i])
	{
		nueva_cad[i] = cad[i];
		i++;
	}
	nueva_cad[i] = '\0';
	return (nueva_cad);
}

/* int main()
{
    char* cad = "cadena a copiar";
    if (ft_strdup(cad) == NULL)
        printf("%s", "no ha podido reservar");
    else
        printf("%s\n", ft_strdup(cad));        

    //COMPROBACION CON LA FUNCION ORIGINAL
    if (strdup(cad) == NULL)
        printf("%s", "no ha podido reservar");
    else
        printf("%s\n", strdup(cad));        
} */