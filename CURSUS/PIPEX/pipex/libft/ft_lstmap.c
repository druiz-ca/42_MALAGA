/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:39:47 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/09 11:36:17 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
- Todas las funciones que usen listas, al usar malloc, se deben comprobar si 
son Null
La función ft_lstmap en C se utiliza para aplicar una función a cada elemento
de una lista enlazada, creando una nueva lista con los resultados

*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*primlst;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	primlst = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (primlst)
			{
				new = primlst->next;
				(*del)(primlst->content);
				free(primlst);
				primlst = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&primlst, new);
		lst = lst->next;
	}
	return (primlst);
}
/* 
int	main(void)
{
	t_list	*lst;

	ft_lstmap(lst, f, del);
}
//falta comprobar que funciona bien, el debuger da fallo al beber el t_list */