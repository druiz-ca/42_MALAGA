/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:45 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:15:42 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// si lo recorro todo con cad*, etc, no funciona!!!
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_cad;
	size_t	i;
	size_t	j;
	size_t	leng_total;

	leng_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_cad = (char *)malloc(sizeof(*s1) * leng_total);
	if (!new_cad)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_cad[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new_cad[j++] = s2[i];
		i++;
	}
	new_cad[j] = 0;
	return (new_cad);
}
/* 
int main()
{
    printf("%s", ft_strjoin("Hola soy ", "pepe"));    
}
 */