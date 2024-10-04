/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:39 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/10 11:26:46 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *cad)
{
	int	i;

	i = 0;
	while (cad[i] != '\0')
		i++;
	return (i);
}

int	contador(const char *str, char c)
{
	int	i;
	int	var;

	i = 0;
	var = 0;
	while (*str)
	{
		if (*str != c && var == 0)
		{
			var = 1;
			i++;
		}
		else if (*str == c)
			var = 0;
		str++;
	}
	return (i);
}

char	*duplicar(const char *str, int inicio, int fin)
{
	char	*palabra;
	int		i;

	i = 0;
	palabra = malloc((fin - inicio + 1) * sizeof(char));
	while (inicio < fin)
		palabra[i++] = str[inicio++];
	palabra[i] = '\0';
	return (palabra);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**new_cad;

	new_cad = malloc((contador(s, c) + 1) * sizeof(char *));
	if (!s || !new_cad)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			new_cad[j++] = duplicar(s, index, i);
			index = -1;
		}
		i++;
	}
	new_cad[j] = 0;
	return (new_cad);
}
