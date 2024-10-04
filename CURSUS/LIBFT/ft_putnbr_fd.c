/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:49:25 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 12:16:21 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// para el nº minimo hay que contemplarlo solo, además, hay que imprimir el 2
//solo y después dejar que el programa siga su curso normal
static void	ft_putchar(char num, int fd)
{
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		n = 147483648;
	}
	if (n == 0)
		ft_putchar('0', fd);
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
	}
	if (n > 0 && n < 10)
	{
		ft_putchar(n + '0', fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/* int	main(void)
{
	ft_putnbr_fd(-2147483648, 2);
}
 */