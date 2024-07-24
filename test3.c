#include "../../inc/push_swap.h"

static void	swap(t_stack_node **head) //Define a function that swaps the positions of the top node and second node of a stack
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->prev->prev = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*head)->prev->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->prev = (*head)->prev; //If so, update its `prev` pointer to point back to the `new head`
	(*head)->next = (*head)->prev; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

void	sa(t_stack_node	**a, bool print) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}

void	sort_three(t_stack_node **a) //Define a function that handles when stack `a` has three nodes, and sorts it
{
	t_stack_node	*biggest_node; //To store a pointer to the biggest node in stack `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a, false); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a, false); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->nbr > (*a)->next->nbr) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a, false); //If so, simply swap the top and second nodes
}