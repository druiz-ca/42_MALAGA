#include <stdio.h>
#include <stdlib.h>

struct t_nodo
{
    int n;
    struct t_nodo *sig;
};
typedef struct t_nodo nodo;

void ft_asignar_ult(nodo **lst, nodo* nodo2)
{
    nodo *aux;

    aux = *lst;
    if(aux->sig == NULL)
    {
        aux->sig = nodo2;
        nodo2->sig = NULL;
    }
}

void ft_malloc2(nodo ***lst)
{
    *lst = (nodo **)malloc(sizeof(nodo *));
}

void ft_rellenar(nodo *nodo, int n)
{
    nodo->n = n;
}

void ft_apuntar(nodo **lst, nodo *nodo1)
{
    *lst = nodo1;
}

void ft_print(nodo **lst)
{
    nodo *aux;
    
    aux = *lst;
    while(aux->sig)
    {
        printf("%i\n", aux->n);
        aux = aux->sig;
    }
}

void ft_malloc(nodo **nodo)
{
    *nodo = malloc(sizeof(nodo));
}

int main()
{
    nodo **lst;
    nodo *nodo1;
    nodo *nodo2;
    nodo *nodo3;
    nodo *aux;
    ft_malloc2(&lst);
    ft_malloc(&nodo1);
    ft_malloc(&nodo2);
    ft_malloc(&nodo3);
    ft_apuntar(lst, nodo1);
    ft_rellenar(nodo1, 1);
    ft_rellenar(nodo2, 2);
    ft_rellenar(nodo3, 3);
    ft_asignar_ult(lst, nodo2);
    ft_asignar_ult(lst, nodo3);
    ft_print(lst);
}