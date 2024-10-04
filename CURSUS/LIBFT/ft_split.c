/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:39 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/23 10:39:37 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCION 
La función split en C se utiliza para dividir una cadena en varias subcadenas
basándose en un delimitador.
    - Reserva (utilizando malloc(3)) un array de strings resultante de separar 
    la string ’s’ en substrings utilizando el caracter ’c’ como delimitador. 
    - El array debe terminar con un puntero NULL.
*/
// DOS ** 
// significa que es un array que contiene arrays, no solo 2 arrays

//Reservo la memoria de la matriz con el nº de arrays que tendra
//Busco en la cad recibida hasta encontrar el carácter recibido 
// 1 para que se salte el delimitador (el espacio)
//¿pq si al final no hay espacio da NULL

// POS_CAD - CONT_CPY EN MALLOC
// resta el nº de car que lleva recorridos de *s x los que 
// lleva recorridos con el contador cont_cpy y así se obtiene el nº de car que
// tiene la palabra que se va a copiar, así se evita tener que declarar variable

#include "libft.h"

static int	contador(const char *str, char c)
{
	int	i;
	int	var;

	i = 0;
	var = 0;
	while (*str)
	{
		if (*str != c && var == 0)
		{
			var = 1;
			i++;
		}
		else if (*str == c)
			var = 0;
		str++;
	}
	return (i);
}

static char	*duplicar(const char *str, int inicio, int fin)
{
	char	*palabra;
	int		i;

	i = 0;
	palabra = malloc((fin - inicio + 1) * sizeof(char));
	while (inicio < fin)
		palabra[i++] = str[inicio++];
	palabra[i] = '\0';
	return (palabra);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		aux;
	char	**new_cad;

	new_cad = malloc((contador(s, c) + 1) * sizeof(char *));
	if (!s || !new_cad)
		return (0);
	i = 0;
	j = 0;
	aux = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			aux = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			new_cad[j++] = duplicar(s, index, i);
			aux = -1;
		}
		i++;
	}
	new_cad[j] = 0;
	return (new_cad);
}
/* 
//FALTA VER QUE TIENE QUE HACER SI AL FINAL NO HAY ESPACIO
//Y CONTEMPLAR LOS ERRORES DE ASIG DE MEM, EL FREE ETC
int	main(void)
{
    char **new_cad = ft_split("pepe nueva cad ", ' ');
	// si al final no hay espacio que tiene que hacer
    printf("%s\n", new_cad[0]);
    printf("%s\n", new_cad[1]);
    printf("%s\n", new_cad[2]);
}
 */