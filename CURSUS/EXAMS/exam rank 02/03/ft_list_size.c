
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;

int ft_list_size(t_list *nodo)
{
    int i = 0;
    while (nodo)
    {
        nodo = nodo->next;
        i++;
    }
    return (i);   
}