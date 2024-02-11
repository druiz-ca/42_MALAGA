/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:52:16 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/03 18:42:36 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// DECLARAR FUNCIONES DENTRO DE LOS PARAMTROS DE OTRA FUNCION:
// void (*del)(void*) ---> el nombre de la función va entre paréntesis y 
// asterisco para indicar que es un puntero a una función
// Y AL LLAMARLA: del(asd)
// FUNCIÓN COMO PARÁMETRO
// - la variable como parámetro no se envía desde el main, sino que se
// asigna con la variable recibida desde la función que reciba a la función!!

/* void	del(void *content)
{
	free(content);
} */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/* 
int	main(void)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	ft_lstdelone(lst, del);
	printf("%s", (char *)lst->content);
}	//Funciona correctamente porque imprime mull
 */