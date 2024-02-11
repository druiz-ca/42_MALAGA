/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:35:34 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 13:01:18 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= 'a' && str[i] >= 'Z' || str[i] >= 'A' && str[i] <= 'Z'))
		return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_str_is_alpha("PEPE"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_alpha("pepe"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_alpha("pepe1"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_alpha("1pepe"));
	printf("%s", ("\n"));
	return (0);
}
