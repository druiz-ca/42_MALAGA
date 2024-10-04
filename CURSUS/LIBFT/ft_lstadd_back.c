/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:27:54 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/03 18:12:37 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
- Cuando recibo un puntero al primer nodo (**) tengo que crear un nuevo puntero
para recorrer la lista para no perder nunca la 1a posición con el **
 */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
/* 
int	main(void)
{
	t_list	*new;
	t_list	**lst;

	lst = (t_list **)malloc(sizeof(t_list *));
	new = (t_list *)malloc(sizeof(t_list));
	ft_lstadd_back(lst, new);
} */