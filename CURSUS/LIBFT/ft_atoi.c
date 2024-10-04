/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:19:29 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPCION: 
    - CONVIERTE CADENA DE CHAR A INT, SOLO CUANDO LOS CHAR SON NUMEROS 
    - ATOI = A TO I(INT)
// ESTO SIRVE PARA MULT. EL RES. POR EL OPERADOR Y CAMBIAR SU SIGNO A NEGATIVO
// al N ser 0 no multiplica la 1a vez que pasa para las unidades
// PARA NO USAR UNA CADENA/PUNTERO INT*  SE MULT. X 10 Y SE SUMA EL 
// SIGUIENTE NUMERO
// CAMBIAMOS EL OP. DEL NUMEROS A NEG. SI ES QUE LO ES
// Comprobación de la función real
// las funciones que sean exclusivas de este programa llevan static delante
- Aprovechar a hacer operaciones en el return para ahorrar lineas de codigo
- cuando una linea es muy larga, se corta despues de completar una comparacion
y la siguiente linea debe llevar un tabulador mas para que se vea que es la
continuacion de la anterior

*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}
/* 
int	main(void)
{
	char	cad[] = "  --234";
	int		n;
	int 	n2;

	n = ft_atoi (cad);
	printf("%i\n", n);
	n2 = atoi(cad);
	printf("%i\n", n2);
}
//LA FUNCION ORIGINAL DA 0 pero la mia da lo que debe dar!!!! */