/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:36:12 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/12 13:32:04 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (str[i] != '\0')
	{
		if ((str[i] < 97 && str[i] >= 32) || (str[i] > 122 && str[i] <= 126))
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
	int		x;

	str = "a";
	x = ft_str_is_lowercase(str);
	printf("%d", x);
	return (0);
}
 */