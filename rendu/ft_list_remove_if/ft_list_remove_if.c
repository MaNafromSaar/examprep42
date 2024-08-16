#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;
    t_list  *tmp;
    
    while (*begin_list && cmp(data_ref, (*begin_list)->data) == 0)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }
    current = *begin_list;
    while(current && current->next)
    {
        if(cmp(data_ref, current->next->data) == 0)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
            current = current->next;
    }
}