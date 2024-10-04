/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:35:39 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/03 18:42:47 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PORQUE NO ESCRIBE PEPE EN EL PRINTF???????
#include "libft.h"

/* void	f(void *content)
{
	content = (void *)"pepe";
} */

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!(lst))
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
int	main(void)
{
	t_list	*lst;
	t_list	*lst2;

	lst = (t_list *)malloc(sizeof(t_list));
	lst2 = (t_list *)malloc(sizeof(t_list));
	lst->next = lst2;
	lst2->next = NULL;
	printf("%s", (char *)lst->content);
	ft_lstiter(lst, f);
}
//no necesita especificar las caracterisiticas de la funcion F porque como
//ya se ha declarado arriba, solo la llama!!! */