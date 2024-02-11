/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:18:07 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:18:34 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - 
*/
// Recibe el char en int xque lo recibe como numero asci
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/* 
int main()
{
    printf("%i\n", ft_isalpha('F'));

    // Comprobación de la función real
    printf("%i\n", isalpha('F'));
} */