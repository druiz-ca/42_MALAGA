/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:37:12 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/03 14:06:37 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
/* 
int	main(void)
{
	char	*s1;
	char	*s2;
	char cad1[]= "Pepe";
	char cad2[]= "pepe";

	s1 = cad1;
	s2 = cad2;
	printf("Funcion:%i\n", strcmp(s1, s2));
	printf("Mia:%i", ft_strcmp(s1, s2));
	return (0);
}
 */