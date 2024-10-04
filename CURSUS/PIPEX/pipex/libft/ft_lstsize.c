/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:58:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 11:05:20 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
- Tengo la duda de si en este se comprueba también el NULL, pero que se devuelve?
 */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cont;
	t_list	*lstaux;

	cont = 0;
	lstaux = (t_list *)lst;
	while (lstaux)
	{
		cont++;
		lstaux = lstaux->next;
	}
	return (cont);
}

/* int	main(void)
{
	t_list *lst;
	t_list *lst2;
	// Creo 2 listas y las enlazo para comprobar que las cuenta bien
	lst = (t_list *)malloc(sizeof(t_list));
	lst2 = (t_list *)malloc(sizeof(t_list));
	lst->next = lst2;
	lst2->next = NULL;
	printf("%i", ft_lstsize(lst));
} */