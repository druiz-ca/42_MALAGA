/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:39 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/03 18:17:45 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCION 
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
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_contdelimitador(const char *s, char c)
{
	int	cont;

	cont = 0;
	while (*s)
	{
		if (*s == c)
			cont ++;
		s++;
	}
	return (cont);
}

static char	**ft_reservamem(const char *s, const char c)
{
	char	**new_cad;

	new_cad = (char **)malloc(ft_contdelimitador(s, c) * sizeof(char *));
	return (new_cad);
}

static char	**comp_reserv_mem(const char *s, const char c)
{
	char	**new_cad;

	new_cad = ft_reservamem(s, c);
	return (new_cad);
}

static char	**ft_copiar(const char *s, char c)
{
	int		pos_new_cad;
	int		contcpy;
	int		poscad;
	int		narray;
	char	**new_cad;

	poscad = 0;
	pos_new_cad = 0;
	contcpy = 0;
	narray = 0;
	new_cad = comp_reserv_mem(s, c);
	while (s[poscad])
	{
		if (s[poscad] == c || s[poscad] == '\0')
		{
			new_cad[narray] = (char *)malloc((poscad - contcpy) * sizeof(char));
			while (contcpy < poscad && s[contcpy] != ' ')
				new_cad[narray][pos_new_cad++] = s[contcpy++];
			new_cad[narray++][pos_new_cad] = '\0';
			contcpy++;
			pos_new_cad = 0;
		}
		poscad++;
	}
	return (new_cad);
}

char	**ft_split(const char *s, char c)
{
	char	**new_cad;

	new_cad = ft_copiar(s, c);
	free(new_cad);
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