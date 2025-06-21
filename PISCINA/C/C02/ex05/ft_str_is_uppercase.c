/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:06:37 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/28 14:21:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (str[i] != '\0')
	{
		if ((str[i] < 65 && str[i] >= 32) || (str[i] > 90 && str[i] <= 126))
		{
			r = 0;
			break ;
		}
		i++;
	}
	return (r);
}
/* 
int	main(void)
{
	char	*str;

	str = "p";
	printf("%d", ft_str_is_uppercase(str));
	return (0);
}
  */