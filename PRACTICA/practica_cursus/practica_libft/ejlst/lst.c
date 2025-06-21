/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:17:09 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/01/13 19:27:38 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Crear una lista y le pongo un nombre
struct nodo {
	int cont;
	struct nodo *sig;
};
// Creo el nombre de la estructura y la variable
typedef struct nodo t_nodo;
// Creo un puntero a la estructura

void ft_enmedio(t_nodo *aux, t_nodo *nodoenmedio, int n)
{
	while (aux->cont != n)
		aux = aux->sig;
	if (aux->cont == n)
	{
		nodoenmedio->cont = 10;
		//primero le da el valor de aux->sig a nodoenmedio->sig
		nodoenmedio->sig = aux->sig;
		//como nodoemmedio ya apunta a donde apuntaba aux->sig
		//ya puedo cambiar el valor de aux->sig a nodoemmedio
		aux->sig = nodoenmedio;
	}
}

void ft(t_nodo *aux)
{
	while (aux)
	{
		aux->cont--;  
		aux = aux->sig;
	}
}

void ft_ft(t_nodo *aux, void (*ft)(t_nodo *))
{
	ft(aux);
}

int ft_longitud_lista(t_nodo *aux)
{
	int i;
	
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->sig;
	}
	return (i);
}

void ft_cortar(t_nodo *aux, int n)
{
	while (aux->cont != n)
		aux = aux->sig;
	if (aux->cont == n)
		aux->sig = NULL;
}

void ft_masuno(t_nodo *aux)
{
	while (aux)
	{
		aux->cont++;
		aux = aux->sig;
	}
}

t_nodo *ft_lstiniadd(t_nodo *primero, t_nodo* nuevoprimero, t_nodo *nodo_uno)
{
	primero = nuevoprimero;
	nuevoprimero->cont = 0;
	nuevoprimero->sig = nodo_uno;
	return (primero);
}

void ft_insertar_lista(t_nodo *aux, t_nodo *nodo_cuatro, t_nodo *nodo_tres)
{
	while (aux->cont != 4)
		aux = aux->sig;
	if (aux->cont == 4)
	{
		aux->sig = nodo_cuatro;
		nodo_cuatro->cont = 5;
		nodo_cuatro->sig = nodo_tres;
	}
}

// funciona igual si devuelvo el puntero como sino
void ft_change_value(t_nodo *aux)
{
	while (aux->cont != 2)
		aux = aux->sig;
	if (aux->cont == 2)
		aux->cont = 4;
}

t_nodo *ft_crear_nodo3(t_nodo *nodo_tres)
{
	nodo_tres = ((t_nodo *)malloc(sizeof(t_nodo)));
	return (nodo_tres);
}

void ft_imp_lista(t_nodo *primero)
{
	while (primero != NULL)
	{
		printf("%i\n", primero->cont);  
		primero = primero->sig;
	}
}

void ft_añadir_last(t_nodo *aux, t_nodo *nodo_tres)
{
	aux->sig = nodo_tres;
	nodo_tres->cont = 3;
	nodo_tres->sig = NULL;
}

t_nodo *ft_recorrer_lista(t_nodo *aux)
{
	while (aux->sig != NULL)
		aux = aux->sig;
	return (aux);
}

int	main (void)
{
	int 	i;
	t_nodo *primero;
	t_nodo *aux;
	t_nodo *nodo_uno;
	t_nodo *nodo_dos;
	t_nodo *nodo_tres;
	t_nodo *nodo_cuatro;
	t_nodo *nuevoprimero;
	t_nodo *nodoenmedio;

	i = 0;
	primero = NULL;
	nodo_uno = malloc(sizeof(t_nodo));
	nodo_dos = malloc(sizeof(t_nodo));
	nodo_cuatro = (t_nodo *)malloc(sizeof(t_nodo));
	nuevoprimero = (t_nodo *)malloc(sizeof(t_nodo));
	nodoenmedio = (t_nodo *)malloc(sizeof(t_nodo));
	// castear el malloc (char *)malloc no es obligatorio, es good practica
	nodo_uno->cont = 1;
	nodo_uno->sig = nodo_dos;
	nodo_dos->cont = 2;
	nodo_dos->sig = NULL;
	primero = nodo_uno;
	aux = primero;

	aux = ft_recorrer_lista(primero);
	nodo_tres = ft_crear_nodo3(nodo_tres);
	ft_añadir_last(aux, nodo_tres);
	ft_change_value(aux);
	ft_insertar_lista(aux, nodo_cuatro, nodo_tres);
	primero = ft_lstiniadd(primero, nuevoprimero, nodo_uno);
	ft_masuno(primero);
	ft_cortar(primero, 6);
	ft_ft(primero, ft);
	ft_enmedio(primero, nodoenmedio, 4);
	ft_imp_lista(primero);
	printf("La longitud es de : %i\n", ft_longitud_lista(primero));
}
