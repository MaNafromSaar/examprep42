#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

// Helper function to create a new node
t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print the list
void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Comparison function
int cmp(void *data1, void *data2)
{
    return strcmp((char *)data1, (char *)data2);
}

// First implementation of ft_list_remove_if
void ft_list_remove_if_v1(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if_v1(begin_list, data_ref, cmp);
	}
	else
	{
		cur = *begin_list;
		ft_list_remove_if_v1(&cur->next, data_ref, cmp);
	}
}

// Second implementation of ft_list_remove_if
void ft_list_remove_if_v2(t_list **begin_list, void *data_ref, int (*cmp)())
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

// Third implementation of ft_list_remove_if
void ft_list_remove_if_v3(t_list **begin_list, void *data_ref, int (*cmp)())
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

int main()
{
    // Create test list
    t_list *list = create_node("data1");
    list->next = create_node("data2");
    list->next->next = create_node("data1");
    list->next->next->next = create_node("data3");
    list->next->next->next->next = create_node("data1");

    printf("Original list:\n");
    print_list(list);

    // Test first implementation
    t_list *test_list_v1 = create_node("data1");
    test_list_v1->next = create_node("data2");
    test_list_v1->next->next = create_node("data1");
    test_list_v1->next->next->next = create_node("data3");
    test_list_v1->next->next->next->next = create_node("data1");
    ft_list_remove_if_v1(&test_list_v1, "data1", cmp);
    printf("List after removing 'data1' with v1:\n");
    print_list(test_list_v1);

    // Test second implementation
    t_list *test_list_v2 = create_node("data1");
    test_list_v2->next = create_node("data2");
    test_list_v2->next->next = create_node("data1");
    test_list_v2->next->next->next = create_node("data3");
    test_list_v2->next->next->next->next = create_node("data1");
    ft_list_remove_if_v2(&test_list_v2, "data1", cmp);
    printf("List after removing 'data1' with v2:\n");
    print_list(test_list_v2);

    // Test third implementation
    t_list *test_list_v3 = create_node("data1");
    test_list_v3->next = create_node("data2");
    test_list_v3->next->next = create_node("data1");
    test_list_v3->next->next->next = create_node("data3");
    test_list_v3->next->next->next->next = create_node("data1");
    ft_list_remove_if_v3(&test_list_v3, "data1", cmp);
    printf("List after removing 'data1' with v3:\n");
    print_list(test_list_v3);

    return 0;
}
