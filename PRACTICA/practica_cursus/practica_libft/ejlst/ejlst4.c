#include <stdio.h>
#include <stdlib.h>

struct t_nodo
{
    int n;
    struct t_nodo *sig;
}; 
typedef struct t_nodo nodo;

void ft_malloc_lst(nodo ***lst) 
{ //puntero del puntero a puntero = puntero de la lista = x referencia para afectar en todo el programa
    *lst = (nodo **)malloc(sizeof(nodo *)); //sino lo malloqueo da seg fault
}
void ft_malloc_nodo(nodo **nodo1) //si la llamo nodo, igual que la esteuctura peta
{
    *nodo1 = (nodo *)malloc(sizeof(nodo));
} // al maloquear siempre se pone solo 1 * aunque la ft lo reciba con 20 *

void ft_apuntar_lst(nodo **lst, nodo *nodo1)
{
    *lst = nodo1;
}

void ft_rellenar_ultimonodo(nodo **lst, int n)
{
    nodo *aux;

    aux = *lst;
    while (aux->sig) // si hacia (aux) da seg fault
        aux = aux->sig;
    aux->n = n;
}
void ft_addback(nodo **lst, nodo *nodo1)
{ // sino malloqueo el nodo2 antes de meterlo en la lista peta, pq???
    nodo *aux;

    aux = *lst;
    while (aux->sig) // (aux) peta
        aux = aux->sig;
    aux->sig = nodo1;
    nodo1->sig = NULL;
}

void ft_print_lst(nodo **lst)
{
    nodo *aux;
    
    aux = *lst;
    while (aux) // si pongo (aux-sig) no imprime el ultimo nodo???
    {
        printf("%i\n", aux->n);
        aux = aux->sig;
    }
}

void ft_rellenar_nodo(nodo **lst, int n, int cont)
{
    nodo *aux;

    aux = *lst;
    while (aux->sig && cont > 0) // (aux && ...) = seg fault
        aux = aux->sig;
        cont--;
    aux->n = n;
}

void ft_addfront(nodo **lst, nodo *nodo1)
{
    nodo *aux;

    aux = *lst;
    nodo1->sig = aux->sig;
    aux->sig = nodo1;
}

void ft_eliminar_nodo(nodo **lst, int cont)
{
    nodo *aux;
    nodo *aux2;

    aux = *lst;
    aux2 = *lst;
    while (aux && cont > 0)
    {
        aux = aux->sig;
        cont--;
    }
    aux2 = aux;
    aux--;
    aux->sig = aux2->sig;
}

int main()
{
    nodo **lst;
    nodo *nodo0;
    nodo *nodo1;
    nodo *nodo2;
    nodo *new_nodo;
    nodo *aux;

    ft_malloc_lst(&lst);
    ft_malloc_nodo(&nodo0);
    ft_malloc_nodo(&nodo1);
    ft_malloc_nodo(&nodo2); 
    ft_malloc_nodo(&new_nodo); 
    // sino lo envio con & tendria que hacer nodo3 = ft_malloc(nodo3);
    ft_apuntar_lst(lst, nodo0);
    ft_addback(lst, nodo1);
    ft_addback(lst, nodo2); 
    ft_rellenar_ultimonodo(lst, 1);
    ft_rellenar_nodo(lst, 1, 1);
    ft_rellenar_nodo(lst, 3, 2);
    ft_addfront(lst, new_nodo);
    ft_rellenar_nodo(lst, 98, 0);
    ft_eliminar_nodo(lst, 2);
    ft_print_lst(lst);
}