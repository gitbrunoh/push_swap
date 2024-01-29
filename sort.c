/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:22:12 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/26 14:22:14 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_both(t_stack_node **a,
                   t_stack_node **b,
                   t_stack_node *cheapest_node,
                   bool reverse) // true for reverse rotation, false for normal rotation
{
    while (*b != cheapest_node->target && *a != cheapest_node) {
        if (reverse) {
            rrr(a, b, false); // Reverse rotate both `a` and `b` nodes
        } else {
            rr(a, b, false); // Rotate both `a` and `b` nodes
        }
    }
    set_position(*a); // Refresh current node positions
    set_position(*b);
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

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	t_stack_node   *stack;

	stack = *a;
	if (!stack)
		return;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest_node = stack;
			break;
		}
		stack = stack->next;
	}
	if (cheapest_node->over_median && cheapest_node->target->over_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node, false);
	else if (!(cheapest_node->over_median) 
		&& !(cheapest_node->target->over_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rotate_both(a, b, cheapest_node, true); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, false);
}

static void	min_on_top(t_stack_node **a) 
{
	while ((*a)->n != find_min(*a)->n)
	{
		if (find_min(*a)->over_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = lenght_of_stack(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target, 'a');
		pa(a, b, false);
	}
	set_position(*a);
	min_on_top(a);
}
