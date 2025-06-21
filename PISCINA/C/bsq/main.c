/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:59:37 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/10 16:14:30 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	const char *nom_map = "file.txt";
	int desc_map = open("file.txt", O_RDONLY);
    char buffer[1024];
	ssize_t bytes_map;

	if (desc_map == -1)
	{
		printf("%s", "error");
		return (1);
	}
	while ((bytes_map = read(desc_map, buffer, sizeof(buffer))) > 0)
	{
		write(1, buffer, bytes_map);
	}
    close(desc_map);
	if (bytes_map == -1)
	{
		printf("%s", "error");
		close(desc_map);
		return (1);
	}
	return (0);
}