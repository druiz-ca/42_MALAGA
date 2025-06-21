#include <stdio.h>
#include <stdlib.h>

struct t_nodo
{
    int n;
    struct t_nodo *sig;
};
typedef struct t_nodo nodo;

void ft_lstclear(nodo **lstcompleta)
{
    nodo *anterior = NULL;
    nodo *actual = *lstcompleta;
    nodo *to_delete;

    while (actual)
    {
        if (actual->n == 0)
        {
            if (anterior)
                anterior->sig = actual->sig;
            else
                *lstcompleta = actual->sig;
            to_delete = actual;
            actual = actual->sig;
            free(to_delete);
        }
        else
        {
            anterior = actual;
            actual = actual->sig;
        }
    }
}

void ft(nodo *ptr)
{
    ptr->n = 0;
}

void ft_change_cont_ft(nodo **lstcompleta, void (*ft)(nodo *))
{
    nodo *ptr;

    ptr = *lstcompleta;
    while (ptr)
    {
        if (ptr->n == 200)
            ft(ptr);
        ptr = ptr->sig;
    }
}

void ft_changecontenido(nodo **lstcompleta, int n)
{
    nodo *ptr;

    ptr = *lstcompleta;
    while (ptr->sig)
    {
        ptr->n *= n;
        ptr = ptr->sig;
    }
    ptr->n *= n;
}
void ft_changecontenido1(nodo **lstcompleta, int n)
{

    nodo *ptr;

    ptr = *lstcompleta;
    while (ptr->sig)
    {
        ptr->n *= n;
        ptr = ptr->sig;
    }
    ptr->n *= n;
}

void ft_addbacklst(nodo **lstcompleta, nodo *nodo5)
{
    nodo *ptr;

    ptr = *lstcompleta;
    //se necesita desreferenciar lstcompleta para poder usarlo
    if (!ptr)
    {
        ptr = nodo5;
        return ;
    }
    else 
    {
        while (ptr->sig)
            ptr = ptr->sig;
        ptr->sig = nodo5;
    }
}

/* void ft_addbacklst(nodo **lstcompleta, nodo *nodo5)
{
    nodo *ptr;

    ptr = *lstcompleta;
    //se necesita desreferenciar lstcompleta para poder usarlo
    if (!*lstcompleta)
    {
        *lstcompleta = nodo5;
        return ;
    }
    else 
    {
        while ((*lstcompleta)->sig)
            *lstcompleta = (*lstcompleta)->sig;
        (*lstcompleta)->sig = nodo5;
    }
} */

void sumar(nodo **lstcompleta)
{
    nodo *ptr;

    ptr = *lstcompleta;
	while (ptr)
	{
		ptr->n--;  
		ptr = ptr->sig;
	}
}

void ft_sumarcontenido(nodo **lstcompleta, void (*sumar)(nodo **))
{
	sumar(lstcompleta);
}

void ft_sumarn(nodo **lstcompleta)
{
    nodo* ptr;

    ptr = *lstcompleta;
    while (ptr)
    {
        ptr->n++;
        ptr = ptr->sig;
    }
}

void ft_insertarnodo(nodo **lstcompleta, nodo *nodonuevo, int n)
{
    nodo *ptr;

    ptr = *lstcompleta;
    while (ptr->n != n)
        ptr = ptr->sig;
    ptr--; // es la solcion para retroceder a donde tiene que señalar al nuevonodo
    nodonuevo->sig = ptr->sig;
    ptr->sig = nodonuevo;
}

void ft_cortarlista(nodo **lstcompleta, int n)
{

    nodo* ptr;

    ptr = *lstcompleta;
    while (ptr->n != n)
        ptr = ptr->sig;
    ptr--; 
    //el while me deja el contador en el siguiente del NULL x lo que no borra nada
    ptr->sig = NULL;
}

void ft_addlstback(nodo **lstcompleta, nodo *nodo2)
{
    nodo *ptr;

    ptr = *lstcompleta;
//aunque vaya a usar el doble puntero desreferenciado, hay que pasarlo doble
    while (ptr->sig)
        ptr = ptr->sig;
    ptr->sig = nodo2;
}

void ft_contarlista(nodo **lstcompleta)
{
    int i = 0;
    nodo *ptr;

    ptr = *lstcompleta;
    while (ptr)
    {
        i++;
        ptr = ptr->sig;
    }
    printf("La lista contiene %i nodos\n", i);
}

void ft_impcontlista(nodo **lstcompleta)
{
    int i = 1;

    nodo* ptr;

    ptr = *lstcompleta;
    while (ptr)
    {
        printf("%i\n", ptr->n);
        ptr = ptr->sig;
        i++;
    }
}

void ft_rellenarnodo(nodo *nodo, int n)
{
    nodo->n = n;
    nodo->sig = NULL;
}

nodo *ft_asignmem(nodo *nodo)
{
    nodo = malloc(sizeof(nodo));
    return (nodo);
}

int main()
{
    nodo *nodo1;
    nodo *nodo2;
    nodo *nodo3;
    nodo *nodo4;
    nodo *nodo5;
    nodo **lstcompleta;
    // lo ideal es usar 2x puntero para mantener la 1a pos de la lista siempre
    // para que no de seg fault, la ft debe devolver el nodo y apuntarlo desde el main
    nodo1 = ft_asignmem(nodo1); 
    nodo2 = ft_asignmem(nodo2);
    nodo3 = ft_asignmem(nodo3);
    nodo4 = ft_asignmem(nodo4);
    nodo5 = ft_asignmem(nodo5);
    lstcompleta = (nodo **)malloc(sizeof(nodo *));
    *lstcompleta = nodo1;
    ft_rellenarnodo(nodo1, 1);
    ft_rellenarnodo(nodo2, 2);
    ft_rellenarnodo(nodo3, 3);
    ft_rellenarnodo(nodo4, 4);
    ft_rellenarnodo(nodo5, 5);
    
    ft_addlstback(lstcompleta, nodo2);
    ft_addlstback(lstcompleta, nodo3);
    ft_addlstback(lstcompleta, nodo4);
    ft_contarlista(lstcompleta);
    ft_cortarlista(lstcompleta, 4);
    ft_contarlista(lstcompleta);
    ft_insertarnodo(lstcompleta, nodo4, 2);
    ft_sumarn(lstcompleta);
    ft_sumarcontenido(lstcompleta, sumar);
    ft_addbacklst(lstcompleta, nodo5);
    ft_changecontenido1(lstcompleta, 10);
    ft_changecontenido(lstcompleta, 10);
    ft_change_cont_ft(lstcompleta, ft);
    ft_lstclear(lstcompleta);
    ft_impcontlista(lstcompleta);
}
/* 
- Para sacar un puntero de un doble puntero: **lst; --> *lst;
 */