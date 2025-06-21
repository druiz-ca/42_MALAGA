/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:18:51 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 13:14:36 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_str_is_printable("pepe"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_printable("PEPE"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_printable("pepe1"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_printable("1pepeñ"));
	printf("%s", ("\n"));
	return (0);
}
 