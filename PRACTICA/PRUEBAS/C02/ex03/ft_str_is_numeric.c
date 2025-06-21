/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:04:17 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 13:01:53 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
	if(!(str[i] >= '0' && str[i] <= '9'))
		return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_str_is_numeric("pepa"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_numeric("998"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_numeric("asd987"));
	printf("%s", ("\n"));
	printf("%d", ft_str_is_numeric("PePa"));
	printf("%s", ("\n"));
	return (0);
}
