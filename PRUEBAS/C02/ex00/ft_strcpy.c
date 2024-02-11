/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:35:30 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 12:37:10 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char dest[4];
	printf("%s", ft_strcpy(dest, "pepa\n"));
	printf("%s", ft_strcpy(dest, "7 9 9 8\n"));
	printf("%s", ft_strcpy(dest, "asd987\n"));
	printf("%s", ft_strcpy(dest, "PePa\n"));


	return (0);
}
 