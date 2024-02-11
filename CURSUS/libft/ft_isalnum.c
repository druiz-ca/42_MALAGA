/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:00 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:19:04 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - IS ALPHA NUMERIC
 */
//- Recibe el char en int xque lo recibe como numero asci
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/* 
int main ()
{
    printf("%i\n", ft_isalnum('9'));

    // Comprobación de la función real
    printf("%i\n", isalnum('9'));
}
 */