#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node) //O nó que eu quero meter no topo já lá está?
	{
		if (stack_name == 'a') //Se não, e for o stack `a`:
		{
			if (top_node->over_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //Se não, e for o stack `b`:
		{
			if (top_node->over_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}