/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:48:02 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/06 13:45:34 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < -2147483647 || nb > 2147483647)
		return (0);
	else
	{
		while (nb > 1)
		{
			nb -= 1;
			res *= nb;
		}
		return (res);
	}
}

int	main (void)
{
	int nb;
	printf("%i", ft_iterative_factorial(5));
}