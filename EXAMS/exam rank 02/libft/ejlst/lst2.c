/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:54:27 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/15 09:10:09 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct n_nodo
{
    int n;
	struct n_nodo *sig;
};
typedef struct n_nodo nodo;

int ft_contlst(nodo *primero)
{
	int i = 0;
	while (primero)
	{
		i++;
		primero = primero->sig;
	}
	return (i);
}

void ft_addlstback(nodo *primero, nodo *new_nodo)
{
	while (primero->sig)
		primero = primero->sig;
	if (primero == NULL) 
		primero->sig = new_nodo;
		new_nodo->sig = NULL;
}

void ft_crearnodo(nodo *nuevo_nodo)
{
	nuevo_nodo = (nodo *)malloc(sizeof(nodo));
}

int main()
{
    nodo *nodo1;
	nodo *nodo2;
	nodo *nodo3;
	nodo *nodo4;
	nodo *primero;

	nodo1 = malloc(sizeof(nodo));
	nodo2 = malloc(sizeof(nodo));
	nodo3 = malloc(sizeof(nodo));
	nodo4 = malloc(sizeof(nodo));
	primero = nodo1; // tengo que apuntarlo a nodo1 despues del malloc
	ft_addlstback(primero, nodo2);
	nodo1->n = 1;
	ft_addlstback(primero, nodo3);
	nodo2->n = 2;
	ft_addlstback(primero, nodo4);
	nodo3->n = 3;
	printf("%i\n", ft_contlst(primero));
	while (primero)
	{
		printf("%i\n", primero->n);
		primero = primero->sig;
	}
}
