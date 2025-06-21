/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:36:23 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/06 10:47:06 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{	
		write(1, str, 1);
		str++;
	}
}

int main(void)
{
	char *str;
	char cadena[] = "manolo";
	str = cadena;
	ft_putstr(str);
	return (0);
}