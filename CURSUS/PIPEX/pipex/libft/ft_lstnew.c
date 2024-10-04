/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:37:40 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/03 18:14:49 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nueva;

	nueva = (t_list *)malloc(sizeof(t_list));
	if (!(nueva))
		return (NULL);
	nueva->content = content;
	nueva->next = NULL;
	return (nueva);
}
/* 
int	main(void)
{
	t_list *estructura;
	estructura = ft_lstnew("pepe");
	printf("%s", (char *)estructura->content);
}	// SE PUEDE CASTEAR HASTA EN EL PARÁMETRO DEL PRINTF !!!!
 */