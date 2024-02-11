/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:12 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:18:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - CUALQUIER CHAR ENTRE 0 Y 127 INCLUIDO
 */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	else
		return (0);
}
/* 
int main ()
{
    printf("%i\n", ft_isascii('a'));

    // Comprobación de la función real
    printf("%i\n", isascii('a'));
} */