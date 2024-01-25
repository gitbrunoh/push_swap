#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int	i;
	int	median;
	int	len;

	i = 0;
	if (!stack)
		return ;
	len = lenght_of_stack(stack);
	if (len % 2 != 0)
		median = len / 2 + 1;
	else
		median = len / 2 + 0.5;
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
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_smallest;

	while (a)
	{
		closest_smallest = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->n < a->n 
				&& current_b->n > closest_smallest)
			{
				closest_smallest = current_b->n;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smallest == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lenght_of_stack(a);
	len_b = lenght_of_stack(b);
	while (a)
	{
		a->cost = a->position; //Isso é uma grande sacada, pois o custo de push é o índice do nó `a` atual
		if (!(a->over_median)) //Está abaixo da mediana? Se sim:
			a->cost = len_a - (a->position);
		if (a->target->over_median) //Se o target de `a` estiver acima da mediana:
			a->cost += a->target->position;
		else //If `a` node is indeed above median and its target `b` node is below median
			a->cost += len_b - (a->target->position);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
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