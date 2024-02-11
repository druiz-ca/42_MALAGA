/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:33:06 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/12/02 12:46:01 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] > s2[i])
		{
			return (1);
		}
		else if (s1[i] < s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*s1;
	char	*s2;
	char cad1[]= "Pepe";
	char cad2[]= "pepE";

	s1 = cad1;
	s2 = cad2;
	/* printf("Funcion:%i\n", strncmp(s1, s2, 2));
	printf("Funcion:%i\n", strncmp(s1, s2, 5));
	printf("Funcion:%i\n", strncmp(s1, s2, 1)); */
	printf("Mio:%i\n", ft_strncmp(s1, s2, 4));
	printf("Mio:%i\n", ft_strncmp(s1, s2, 3));
	printf("Mio:%i\n", ft_strncmp(s1, s2, 2));
	printf("Mio:%i\n", ft_strncmp(s1, s2, 1));
	printf("Mio:%i\n", ft_strncmp(s1, s2, 0));

	return (0);
}
