/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:08:17 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:16:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	salto;

	salto = '\n';
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, &salto, 1);
}

/* int main()
{
    ft_putendl_fd("manolo", 2);
} */