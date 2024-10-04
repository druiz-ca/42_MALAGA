/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:04:57 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/03/29 11:44:51 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *cad)
{
	if (!cad)
		free(cad);
	return (NULL);
}

char	*ft_strjoin(char *buffer, char *buffer_aux)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * 1);
		ft_free(buffer);
		buffer[0] = '\0';
	}
	new_buffer = malloc(ft_strlen(buffer) + ft_strlen(buffer_aux) + 1);
	if (!new_buffer)
		ft_free(new_buffer);
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	i = 0;
	while (buffer_aux[i])
		new_buffer[j++] = buffer_aux[i++];
	new_buffer[j] = '\0';
	free (buffer);
	return (new_buffer);
}

char	*ft_strchr(char *buffer, char salto)
{
	while (*buffer)
	{
		if (*buffer == salto)
			return (buffer);
		buffer++;
	}
	if (salto == '\0')
		return (buffer);
	return (NULL);
}

char	*ft_substr(char *buffer, unsigned int inicio, size_t long_a_copiar)
{
	size_t	i;
	char	*resto_de_buffer;

	i = 0;
	resto_de_buffer = malloc(sizeof(char) * (long_a_copiar + 1));
	if (!resto_de_buffer)
		return (NULL);
	while (inicio < ft_strlen(buffer) && i < long_a_copiar)
		resto_de_buffer[i++] = buffer[inicio++];
	resto_de_buffer[i] = '\0';
	return (resto_de_buffer);
}

size_t	ft_strlen(char *cad)
{
	size_t	i;

	i = 0;
	if (!cad)
		return (0);
	while (cad[i])
		i++;
	return (i);
}
