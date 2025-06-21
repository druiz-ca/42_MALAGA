/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:31:11 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/08 14:14:06 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdio.h>
/* char *ft_calc(int res)
{
	char *nom_num;
	int num;

	int open ("numbers.dict", O_RDONLY);
	int close ("numbers.dict");
	if (res = 1)
	{
		int read("numbers.dict", );
		write(1, &res, 3);
	}
	
	
	return (nom_num);
}
*/
char ft_asignar(char numero)
{
	int i;
	char nueva_cad[20]; // no es lo mismo * que [] pq [] no lo reconoce fuera de la funcion
	i = 0;
	nueva_cad[i] = numero;
	i++;
	//write(1, nueva_cad, 1);
	return (nueva_cad[0]);
}
char ft_putnbr(int res)
{
	if (res >= 0 && res < 10)
	{
		ft_asignar(res + '0');
	}	
	if (res > 9)
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
	return (res);
}

int	ft_atoi(char *argv)
{
	int res = 0;
	char *e = "Error\n"; 

	if ((*argv >= 32 && *argv < 48) || (*argv > 57 && *argv <= 126))
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	}
	if (*argv == '\t' || *argv == '\n' || *argv == '\v' || *argv == '\f'
		|| *argv == '\r' || *argv == ' ')
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	}
	if ((*argv >= 'a' && *argv <= 'z') || (*argv >= 'A' && *argv <= 'Z'))
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	}
	while (*argv >= '0' && *argv <= '9')
	{
		res *= 10;
		res += *argv - '0';
		argv++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int res;
	char res_char;
	
	res = ft_atoi(argv[1]);
	res_char = ft_putnbr(res);
}