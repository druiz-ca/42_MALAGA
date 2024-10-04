/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:19:13 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/23 12:31:17 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - COMPARA 2 CADENAS HASTA UN N DE CARACTERES Y DEVUELVE LA DIFERENCIA ENTRE
	EL 1ER CARACTER DISTINTO
	La función strncmp recorre str1 y str2 hasta que encuentra un carácter
	diferente o hasta que ha comparado n caracteres. Si encuentra un carácter
	diferente, devuelve la diferencia entre los códigos ASCII de los caracteres.
	Si no encuentra un carácter diferente, devuelve 0.
*/
// IMPORTANTE PONER I < N Y NO N >= 0 PQ EL N PASADO PUEDE SER MAYOR A LA CADENA
// menor o igual a n para que contemple que la n sea 0, es decir, la 1
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int main()
{
    printf("%i\n", ft_strncmp("pepeE", "pepee", 5));

    // Comprobación de la función real
    printf("%i\n", strncmp("pepeE", "pepee", 5));
}
 - se usa unsigned char pq los caracteres con valores ASCII por encima de 127
se interpretarán como números negativos, Cuando restas dos char, el resultado
puede ser incorrecto si uno de los caracteres tiene un valor ASCII por encima 
de 127. Para evitar este problema, se convierten los char a unsigned char antes
de la resta. Esto asegura que todos los caracteres se interpreten como números
positivos 
 */