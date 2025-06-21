/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:36:12 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 13:05:41 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_str_is_lowercase("pepe"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_lowercase("PEPE"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_lowercase("pepe1"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_lowercase("1pepe"));
	printf("%s", ("\n"));
	return (0);
}
