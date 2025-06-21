/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:35:34 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/12 13:17:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
		{
			return (0);
			break ;
		}
		i++;
	}
	return (1);
}
/* 
int	main(void)
{
	char	*str;

	str = "20";
	printf("%d", ft_str_is_alpha(str));
	return (0);
}
 */