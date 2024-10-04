/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:16:10 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 11:01:59 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
- no entiendo xp el new apunta a lst y luego el lst a new
 */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new || !lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* int	main(void)
{
	t_list	**lst;
	t_list	*new;
	int i = 0;
	new = (t_list *)malloc(sizeof(t_list));
	lst = (t_list **)malloc(sizeof(t_list *));
	ft_lstadd_front(lst, new);
	while (*lst)
	{
		*lst = (*lst)->next;
		i++;
		printf("%i", i);
	}
} */
