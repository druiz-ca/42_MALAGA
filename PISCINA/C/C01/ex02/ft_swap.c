/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:40:36 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/12 11:17:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	cambio_a;
	int	cambio_b;

	cambio_a = *a;
	cambio_b = *b;
	*a = cambio_b;
	*b = cambio_a;
}

int	main(void)
{
	int	*conta;
	int	*contb;
	int	a;
	int	b;

	a = 1;
	b = 2;
	conta = &a;
	contb = &b;
	ft_swap(conta, contb);
	return (0);
}
