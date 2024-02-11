/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:31:59 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/09 12:29:31 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ERRORES
- no inicializar los puntero o listaas a NULL
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	aux = NULL;
	if (lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = aux;
		}
	}
}
/* 
int	main(void)
{
	t_list	**lst;

	ft_lstclear(lst, del);
}
 */