/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:32:44 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/12 11:35:43 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	cont_a;
	int	cont_b;

	cont_a = *a;
	cont_b = *b;
	*a = cont_a / cont_b;
	*b = cont_a % cont_b;
}

int	main(void)
{
	int	*a;
	int	*b;
	int	pa;
	int	pb;

	pa = 13;
	pb = 22;
	a = &pa;
	b = &pb;
	ft_ultimate_div_mod(a, b);
	return (0);
}
