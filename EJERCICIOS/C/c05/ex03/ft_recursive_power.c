/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:01:11 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/05 19:28:18 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_recursive_power(int nb, int power)
{
	power = nb;
	if (nb < 0)
		return (0);
	else
	{	
		if (nb > 1)
		{
			nb--;
			power *= ft_recursive_power(nb, power);
		}
		return (power);
	}
}

int	main(void)
{
    printf("%i", ft_recursive_power(5, 5));
}
