#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int counter;

    if (!begin_list)
        return (0);
    counter = 1;
    while (begin_list->next != NULL)
    {
        begin_list = begin_list->next;
        counter += 1;
    }
    return (counter);
}