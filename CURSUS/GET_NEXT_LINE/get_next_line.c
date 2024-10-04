/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:48:44 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/03/29 11:54:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_leer(int fd, char *buffer)
{
	int		bytes_leidos;
	char	*buffer_aux;

	bytes_leidos = 1;
	buffer_aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_aux)
		ft_free(buffer_aux);
	buffer_aux[0] = '\0';
	while (bytes_leidos > 0 && !ft_strchr(buffer_aux, '\n'))
	{
		bytes_leidos = read(fd, buffer_aux, BUFFER_SIZE);
		if (bytes_leidos > 0)
		{
			buffer_aux[bytes_leidos] = '\0';
			buffer = ft_strjoin(buffer, buffer_aux);
		}
	}
	free(buffer_aux);
	if (bytes_leidos == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_linea(char *buffer)
{
	char	*linea;
	char	*ptr_buffer;
	int		len;

	ptr_buffer = ft_strchr(buffer, '\n');
	len = (ft_strlen(buffer) - ft_strlen(ptr_buffer)) + 1;
	linea = ft_substr(buffer, 0, len);
	if (!linea)
		return (NULL);
	return (linea);
}

char	*ft_resto_buffer(char *buffer)
{
	char	*resto_buffer;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!ft_strchr(buffer, '\n'))
		ft_free(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	resto_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!resto_buffer)
		ft_free(resto_buffer);
	while (buffer[i])
		resto_buffer[j++] = buffer[i++];
	resto_buffer[j] = '\0';
	free(buffer);
	return (resto_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*linea;

	if (fd < 0)
		return (NULL);
	if (buffer == NULL || (buffer != NULL && ft_strchr(buffer, '\n') == NULL))
		buffer = ft_leer(fd, buffer);
	if (!buffer)
		return (NULL);
	linea = ft_linea(buffer);
	if (!linea)
		return (NULL);
	buffer = ft_resto_buffer(buffer);
	return (linea);
}

/* int main()
{
	int fd;
	fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
} */