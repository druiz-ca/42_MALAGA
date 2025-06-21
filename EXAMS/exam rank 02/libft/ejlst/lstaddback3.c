#include <stdio.h>
#include <stdlib.h>

struct t_nodo
{
    int n;
    struct t_nodo *sig;
};
typedef struct t_nodo nodo;

void ft_lstaddback3(nodo **lst, nodo *nodo1)
{
    nodo *aux;

    aux = *lst;
    while (aux->sig)
        aux = aux->sig;
    aux->sig = nodo1;
}

int main()
{
    nodo **lst;
    nodo *nodo1;

    lst = (nodo **)malloc(sizeof(nodo *));
    nodo1 = (nodo *)malloc(sizeof(nodo));

    nodo1->n = 1;
    ft_lstaddback3(lst, nodo1);
    while (*lst)
    {
        printf("%i",(*lst)->n);
        *lst++;
    }
}