/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:32:39 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/06 13:45:46 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb)
{
	int	res;
	int	i;

	res = nb;
	i = nb;
	if (nb < 0)
		return (0);
	while (i > 1)
	{
		res *= nb;
		i--;
	}
	return (res);
}

int main(void)
{
    printf("%i", ft_iterative_power(5));
}