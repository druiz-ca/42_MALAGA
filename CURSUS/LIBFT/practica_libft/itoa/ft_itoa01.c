/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:45:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/10 09:58:37 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCION
    - Es un putchar en realidad, está el revés, recibe un int y devuelve una cad
- itoa si o si tiene que revertir el orden de los caracteres

// no se puede usar recursividad pq borra la mem cada vez q la llama
62 - 12 pq es el maximo de digitos que puede tener un int + el signo
//voy borrandolo de atras para adelante
// Ahora hay que invertir la cadena
// recorro la cad para tener la longitud
// resto 1 para que no cuente el \0
// mientras no se crucen en el medio
//intercambio el primer y ultimo valor, el segundo y penultimo
//avanzo en la cadena
//retrocedo en la cadena
//CAD[i++] = usa el i con su valor actual y luego lo incrementa
Cuando se declara un char se debe inicializar en '\0', y un puntero a NULL

*/
#include "libft.h"

static char	*ft_inver(char var, char *cad, int k, int j)
{
	while (k < j)
	{
		var = cad[k];
		cad[k] = cad[j];
		cad[j] = var;
		k++;
		j--;
	}
	return (cad);
}

static char	*ft_ispos(int n, char *cad, int i)
{
	while (n > 0)
	{
		cad[i++] = (n % 10) + '0';
		n = n / 10;
	}
	cad[i] = '\0';
	return (cad);
}

static int	ft_posfinal(char *cad, int j)
{
	while (cad[j])
		j++;
	j--;
	return (j);
}

static char	*ft_reservamem(char *cad)
{
	cad = (char *)malloc(12 * sizeof(char));
	return (cad);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*cad;
	int		k;
	int		j;
	char	var;

	i = 0;
	k = 0;
	cad = NULL;
	var = '\0';
	if (!(ft_reservamem(cad)))
		return (NULL);
	if (n == 0)
		cad[i] = '0';
	if (n < 0)
	{
		cad[i++] = '-';
		n = -n;
	}
	ft_ispos(n, cad, i);
	k = 1;
	j = 0;
	j = ft_posfinal(cad, j);
	ft_inver(var, cad, k, j);
	return (cad);
}

int main()
{
    printf("%s", ft_itoa(-123456789));

    //printf("%s", ft_itoa(123456789));
	    ///printf("%s", ft_itoa(0));

}