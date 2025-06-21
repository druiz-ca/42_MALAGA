/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:48:14 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/02 18:13:41 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/* 
int main(void)
{
	char	*dest;
	char	*src;
	char cad1[]= "pepe";
	char cad2[]= "manolo";
	char	*dest2;
	char	*src2;
	char cad12[]= "pepe";
	char cad22[]= "manolo";
	
	dest = cad1;
	src = cad2;
	dest2 = cad12;
	src2 = cad22;
	printf("%s\n", strncat(dest, src, 4));
	printf("%s\n", ft_strncat(dest2, src2, 4));
	return (0);
}
 */