/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:53 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:19:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - Pone los bytes de un bloque de mem. a 0 (limpia la memoria antes de usarla)
    - no devuelve nada = VOID
*/
// se usa void cuando el valor es universal y no específico (char, int)
// viene bien cuando tenía un tipo de dato y se va a cambiar a otro
// Comprobación de la función real
// no imprime nada pq no devuelve nada
#include "libft.h"

void	ft_bzero(void *cad, size_t n)
{
	int		i;
	char	*p;

	i = 0;
	p = cad;
	while (n > 0)
	{
		p[i] = 0;
		i++;
		n--;
	}
}
/* 
int main ()
{
    char cad[] = "manolo";
    ft_bzero(cad, 1);
    printf("%s\n", cad);

    bzero(cad, 1); 
    printf("%s\n", cad);
}
 */