/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:02:05 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:14:51 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
La función strtrim en C se utiliza para eliminar los caracteres especificados 
del principio y del final de una cadena.
strtrim toma dos argumentos: str, que es la cadena que se va a recortar, y
chars, que es la cadena de caracteres que se van a eliminar del principio y
del final de str. La función strtrim encuentra el primer y el último carácter
en str que no está en chars, y crea una nueva cadena con los caracteres entre
ellos. Devuelve la nueva cadena.

//Cuenta desde delante
// Ahora cuenta por atrás
//comprueba que malloc reserve bien la memoria
// Crea la nueva cadena restanto i and cont2
// Copia a la nueva cadena
// Me daba 3 error que no comprendía, la causa, solo que estaba llamando a una
// función que la había desarrollado debajo de esa, y tiene que ir encima!!!
- El comprobar el NULL solo se hace en las funciones donde asignamos memoria 
con malloc, el resto no.
- He borrado el j= 0 antes del break
 */

#include "libft.h"

static int	ft_buscador(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cad;
	size_t	i;
	size_t	inicio;
	size_t	final;

	inicio = 0;
	while (s1[inicio] && ft_buscador(s1[inicio], set))
		inicio++;
	final = ft_strlen(s1);
	while (final > inicio && ft_buscador(s1[final - 1], set))
		final--;
	cad = (char *)malloc(sizeof(*s1) * (final - inicio + 1));
	if (!cad)
		return (NULL);
	i = 0;
	while (inicio < final)
		cad[i++] = s1[inicio++];
	cad[i] = 0;
	return (cad);
}

/* int	main(void)
{
	printf("%s", ft_strtrim("manoloman", "nam"));
}
 */