/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:54:57 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/07 11:51:38 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexitoa(unsigned int num)
{
	char			*new_cad;
	unsigned int	n;
	int				leng;

	leng = 0;
	n = num;
	while (n > 0)
	{
		leng++;
		n /= 16;
	}
	new_cad = malloc(sizeof(char) * (leng + 1));
	new_cad[leng--] = '\0';
	if (num == 0)
		new_cad[0] = '0';
	while (num > 0)
	{
		new_cad[leng--] = (num % 16) + '0';
		num /= 16;
	}
	return (new_cad);
}
// fallaba: asignaba el n antes de hacer *1, al ser negativo no entraba
