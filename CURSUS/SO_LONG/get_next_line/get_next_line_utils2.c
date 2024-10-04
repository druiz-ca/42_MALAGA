/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:48:44 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/06/27 19:43:30 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_newarray(char *x, unsigned int num, long int len)
{
	while (num > 0)
	{
		x[len--] = (num % 10) + 48;
		num = num / 10;
	}
	return (x);
}

static long int	ft_longitud(int n)
{
	int	longitud;

	longitud = 0;
	if (n <= 0)
		longitud = 1;
	while (n != 0)
	{
		longitud++;
		n = n / 10;
	}
	return (longitud);
}

char	*ft_itoa(int n)
{
	char			*cad;
	int				len;
	unsigned int	num;
	int				operador;

	operador = 1;
	len = ft_longitud(n);
	cad = (char *)malloc(sizeof(char) * (len + 1));
	if (!(cad))
		return (NULL);
	cad[len--] = '\0';
	if (n == 0)
		cad[0] = '0';
	if (n < 0)
	{
		operador *= -1;
		num = n * -1;
		cad[0] = '-';
	}
	else
		num = n;
	cad = ft_newarray(cad, num, len);
	return (cad);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen2(char *cad)
{
	int	i;

	i = 0;
	if (!cad)
		return (0);
	while (cad[i])
		i++;
	return (i);
}
