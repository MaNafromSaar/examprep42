#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  **current;
    t_list  *tmp;

    current =  begin_list;
    while (*current)
    {
        if (cmp((*current)->data, data_ref) == 0)
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