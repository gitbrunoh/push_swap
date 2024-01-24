#include "push_swap.h"

void	tiny_sort(t_stack_node **a) //Define a function that handles when stack `a` has three nodes, and sorts it
{
	t_stack_node	*biggest_node; //To store a pointer to the biggest node in stack `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a, false); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a, false); //If so, reverse rotate the bottom node, to the top of the stack
	struct s_stack_box; // Forward declaration of struct s_stack_box
	if ((*a)->n > (*a)->next->n) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a, false); //If so, simply swap the top and second nodes
}