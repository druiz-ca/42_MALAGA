/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:02:05 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/10 10:30:51 by druiz-ca         ###   ########.fr       */
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

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_strleng(const char *cad)
{
	size_t	i;

	i = 0;
	while (cad[i])
		i++;
	return (i);
}

static int	ft_compdel(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	j = 0;
	cont = ft_strlen(s1);
	while (cont > 0)
	{
		if (s1[i] == set[j])
			i++;
		while (s1[i] != set[j])
		{
			if (set[j] == '\0')
			{
				j = 0;
				break ;
			}
			j++;
		}
		cont--;
	}
	return (i);
}

static char	*ft_asignacion(const char *s1, char *new_cad, int i, int cont2)
{
	int	k;

	k = 0;
	while (i < cont2)
	{
		new_cad[k] = s1[i];
		k++;
		i++;
	}
	return (new_cad);
}

static int	ft_comptras(const char *s1, const char *set, int i)
{
	int	j;
	int	i2;
	int	cont;
	int	cont2;

	i2 = 0;
	j = 0;
	cont = ft_strlen(s1);
	cont2 = 0;
	while (cont > i)
	{
		if (s1[i2] == set[j])
			i2--;
		while (s1[i2] != set[j])
		{
			if (set[j] == '\0')
				break ;
			j++;
		}
		cont--;
		cont2++;
	}
	return (cont2);
}

char	*ft_strtrim(const char	*s1, const char	*set)
{
	int		i;
	char	*new_cad;
	int		cont2;

	cont2 = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	i = ft_compdel(s1, set);
	cont2 = ft_comptras(s1, set, i);
	new_cad = (char *)malloc((ft_strleng(s1) - i - cont2) * sizeof(char));
	if (!(new_cad))
		return (NULL);
	new_cad = ft_asignacion(s1, new_cad, i, cont2);
	return (new_cad);
}
/* 
int	main(void)
{
	printf("%s", ft_strtrim("manoloman", "nam"));
}
 */