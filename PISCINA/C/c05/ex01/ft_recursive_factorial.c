/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:16:03 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/06 11:45:07 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb > 20000000 || nb > 20000000)
		return (0);
	else
	{
		if (nb > 1)
		{
			res *= ft_recursive_factorial(nb - 1);
		}
	}
	return (res);
}

int main(void)
{
	printf("%i", ft_recursive_factorial(5));
}