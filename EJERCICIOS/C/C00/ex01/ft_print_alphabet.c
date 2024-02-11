/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:50:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/20 19:27:56 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
	{
	char	caracter;

	caracter = 'a';
	while (caracter <= 'z')
	{
		write(1, &caracter, 1);
caracter ++;
	}
}
/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/