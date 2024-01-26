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

static void	move_a_to_b(t_stack_node **a, t_stack_node **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack_node	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->over_median && cheapest_node->target->over_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node, false);
	else if (!(cheapest_node->over_median) 
		&& !(cheapest_node->target->over_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rotate_both(a, b, cheapest_node, true); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, false); 
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
		move_b_to_a(a, b);
	}
	set_position(*a);
	min_on_top(a);
}
