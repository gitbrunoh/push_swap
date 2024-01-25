#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = lenght_of_stack(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->over_median = true;
		else
			stack->over_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack_node	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->n < a->n 
				&& current_b->n > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->n; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target = find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = lenght_of_stack(a);
	len_b = lenght_of_stack(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->cost = a->position; //Assign the current `a` node's push cost, its' index value
		if (!(a->over_median)) //Check if the above_median data is false, meaning it is below median
			a->cost = len_a - (a->position); //If so, update `a` node's push cost to the stack's length - index
		if (a->target->over_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->cost += a->target->position; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->cost += len_b - (a->target->position); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_stack_node *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	t_stack_node	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	set_position(a);
	set_position(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}