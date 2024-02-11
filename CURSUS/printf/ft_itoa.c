/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:12 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/02/07 13:15:37 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// fallo: asignaba el n antes de hacer *1, al ser negativo no entraba

static char	*ft_malloc(char *new_cad, int leng)
{
	new_cad = malloc(sizeof(char) * (leng + 1));
	if (!new_cad)
		return ((char *) NULL);
	return (new_cad);
}

static void	ft_n_menor(int *n, int *op, int *leng)
{
	*n *= -1;
	*op = '-';
	*leng += 1;
}

static void	ft_n_mayor(int *n, int *leng)
{
	*n /= 10;
	*leng += 1;
}

char	*ft_itoa(int num)
{
	char	*new_cad;
	int		n;
	int		leng;
	int		op;

	new_cad = NULL;
	leng = 0;
	if (num < 0)
		ft_n_menor(&num, &op, &leng);
	n = num;
	while (n > 0)
		ft_n_mayor(&n, &leng);
	new_cad = ft_malloc(new_cad, leng);
	new_cad[leng--] = '\0';
	if (num == 0)
		new_cad[0] = '0';
	while (num > 0)
	{
		new_cad[leng--] = (num % 10) + '0';
		num /= 10;
	}
	if (op == '-')
		new_cad[0] = '-';
	return (new_cad);
}
/*
- al llamar a una función pasando un puntero de una var, no deja sumarle
1 al puntero haciendo leng++, sino que hay que hacer leng += 1
*/