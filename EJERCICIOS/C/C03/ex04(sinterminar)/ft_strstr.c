/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/02 12:45:05 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
    {
        while (to_find[j] != '\0')
        {
        	if (str[i] == to_find[j])
			{
				
			}
			else 
			
				return(NULL);
        j++;
        i++;
        }
		
    }
	return (str);
}

int main(void)
{
	char	*str;
	char	*to_find;
	char cad1[]= "busca a pepe";
	char cad2[]= "pepe";

	str = cad1;
	to_find = cad2;
	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
