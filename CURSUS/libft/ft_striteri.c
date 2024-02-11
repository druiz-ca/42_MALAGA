/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:16:41 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/09 09:22:02 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
ERRORES
- no contemplaba el caso de que la cadena estuviera vacia
  como la función es void, simplemente se pone un return
  recorria el while como puntero, en vez de s[i] ??? no entiendo xq falla
 */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/* 
int main()
{
    char cad[] = "manolo"; 
	// me daba error xq qria modificar la cadena desde el puntero
    printf("%s", ft_striteri(cad, f));
} */