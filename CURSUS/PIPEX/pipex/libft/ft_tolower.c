/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:19:27 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:14:37 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
- Pasa a minuscula la LETRA recibida, si no es mayuscula no lo toca
- para imprimir un caracter con int, poner "c" en el PRINTF!!
- para recibir como parámetro un char en una variable int, poner 'c' al
llamar a la función porque así lo recibirá como valor ASCII
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/* int	main(void)
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('A'));
}
 */