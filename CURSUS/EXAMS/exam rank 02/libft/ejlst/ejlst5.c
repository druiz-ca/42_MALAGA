#include <stdio.h>
#include <stdlib.h>

struct t_nodo
{
    int n;
    struct t_nodo *sig;
};
typedef struct t_nodo nodo;

void ft_malloc_lst(nodo ***lst)
{
    *lst = (nodo **)malloc(sizeof(nodo *));
}
void ft_malloc_nodo(nodo **nodox)
{
    *nodox = (nodo *)malloc(sizeof(nodo *));
}
void ft_addback(nodo **lst, nodo* nodox)
{
    nodo *aux;
    aux = *lst;
    while (aux->sig)
        aux = aux->sig;
    aux->sig = nodox;
}

void ft_apuntar_lst(nodo **lst, nodo *nodox)
{
    *lst = nodox;
}
void ft_rellenar_lst(nodo *nodox, int n)
{
    nodox->n = n;
}

void ft_print_lst(nodo **lst)
{
    nodo *aux;
    aux = *lst;

    while (aux) // no imprime con (aux->sig)
    {
        printf("%i\n", aux->n);
        aux = aux->sig;
    }
}
void ft_addfront(nodo **lst, nodo *nodox)
{
    nodo *aux;
    aux = *lst;
    nodox->sig = aux->sig;
    aux->sig = nodox;
}
void ft_eliminar_nodo(nodo **lst, int n)
{
    nodo *aux;
    aux = *lst;
    nodo *aux2;
    while (aux->sig && n--)
        aux = aux->sig;
    aux2 = aux->sig;
    aux--;
    aux->sig = aux2;
}

int main()
{
    nodo **lst;
    nodo *nodo0;
    nodo *nodo1;
    nodo *nodo2;
    nodo *nodo3;
    nodo *nodo00;

    ft_malloc_lst(&lst);
    ft_malloc_nodo(&nodo0);
    ft_apuntar_lst(lst, nodo0);
    ft_rellenar_lst(nodo0, 0);
    ft_malloc_nodo(&nodo1);
    ft_addback(lst, nodo1); // se puede apuntar sin hacer malloc
    ft_rellenar_lst(nodo1, 1);
    ft_malloc_nodo(&nodo2);
    ft_addback(lst, nodo2);
    ft_rellenar_lst(nodo2, 2);
    ft_malloc_nodo(&nodo3);
    ft_addback(lst, nodo3);
    ft_rellenar_lst(nodo3, 3);
    ft_malloc_nodo(&nodo00);
    ft_rellenar_lst(nodo00, 00);
    ft_addfront(lst, nodo00);
    ft_eliminar_nodo(lst, 2);
    ft_print_lst(lst);
}