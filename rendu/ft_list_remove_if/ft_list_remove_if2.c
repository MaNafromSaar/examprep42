#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list **current = begin_list;
    t_list *tmp;

    while (*current)
    {
        if (cmp(data_ref, (*current)->data) == 0)
        {
            tmp = *current;
            *current = (*current)->next;
            free(tmp);
        }
        else
        {
            current = &(*current)->next;
        }
    }
}
