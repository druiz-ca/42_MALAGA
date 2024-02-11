/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:26:18 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/29 12:58:04 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	dest[7];
	printf("%s", ft_strncpy(dest, "pepito\n", 12));
	printf("%s", ft_strncpy(dest, "pepito\n", 4));
	printf("%s", ft_strncpy(dest, "pepito\n", 2));
	printf("%s", ft_strncpy(dest, "pepito\n", 8));
	return (0);
}
