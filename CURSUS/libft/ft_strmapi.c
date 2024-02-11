/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:58:20 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:15:07 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* DESCRIPCION
La función strmapi en C se utiliza para aplicar una función a cada carácter de
una cadena, pasando el índice del carácter y el carácter mismo a la función, y
creando una nueva cadena con los resultados. 
- cuando pasamos un puntero a una función x parametro, no tiene que llamarse
como la función, la declaramos en los paramtros como un puntero nuevo y él
ya sabe a qué funcón se refiere

ERRORES
- el malloc no usa el sizeof, sino el tamaño de la cadena
- no había sumado el \0 al tamaño de la cadena en el malloc con + 1
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* 
int main()
{
    printf("%s", ft_strmapi("manolo", ft_change));
} */