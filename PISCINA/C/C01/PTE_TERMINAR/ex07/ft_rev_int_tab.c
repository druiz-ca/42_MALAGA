/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:21:54 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/25 17:47:49 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(char *tab)
{
	int		i;
	int		j;
	char	inter;

	j = 1;
	i = 0;
	//while (tab[i] != '\0' && tab[j] != '\0')
	//{
		if (tab[j] < tab[i])
		{
			inter = tab[j];
			//tab[j] = tab[i];
			//tab[i] = tab[j];
		i++;
		j++;
        write(1, &tab[j], 1);
    //    }
	}
	
}

int	main(void)
{
	char *tab;
	//int size;
	tab = "cba";
	//size = 3;
	ft_rev_int_tab(tab);
	return (0);
}