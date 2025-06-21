/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:06:37 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 13:09:01 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_str_is_uppercase("pepe"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_uppercase("PEPE"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_uppercase("pepe1"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_uppercase("1pepe"));
	printf("%s", ("\n"));
	return (0);
}
 