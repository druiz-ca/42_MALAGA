/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:50:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/20 19:24:28 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
	{
	char	number;

	number = '0';
	while (number <= '9')
	{
		write(1, &number, 1);
		number ++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/