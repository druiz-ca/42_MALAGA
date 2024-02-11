/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:50:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/20 20:10:22 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
	{
	char	positivo;
	char	negativo;

	positivo = 'P';
	negativo = 'N';
	if (n < 0)
	{
		write(1, &negativo, 1);
	}
	else
	{
		write(1, &positivo, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(-5);
	return (0);
}
*/