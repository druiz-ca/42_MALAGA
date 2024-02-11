/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:19:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/12/01 18:55:56 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	comprobacion(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	res;
	int	oper;

	res = 0;
	oper = 1;
	i = comprobacion(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			oper = -oper;
		i++;
	}
	while (str[i] >= 'a' && str[i] <= 'z')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	res *= oper;
	return (res);
}

int	main(void)
{
	char	*str = "  --+--+123asd456";

	printf("%d", ft_atoi(str));
	//printf("%d", atoi(str)); // función original = poner libreria
	return (0);
}