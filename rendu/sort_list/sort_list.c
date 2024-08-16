#include "sort_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int     tmp;
    t_list  *start;

    tmp = 0;
    start = lst;
    if (!lst)
        exit (1);
    while (lst && lst->next)
    {
        if (cmp(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = start;
        }
        else
        {
            lst = lst->next;
        }
    }
    lst = start;
    return (lst);
}