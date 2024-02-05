/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:22:12 by brunhenr          #+#    #+#             */
/*   Updated: 2024/02/05 16:40:14 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node,
					bool reverse)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
	{
		if (reverse)
			rrr (a, b);
		else
			rr (a, b);
	}
	set_position (*a);
	set_position (*b);
}

static void	bring_node_to_top(t_stack_node **stack,
					t_stack_node *top_node,
					char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->over_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->over_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*stack;

	stack = *a;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	if (cheapest_node->over_median && cheapest_node->target->over_median)
		rotate_both (a, b, cheapest_node, false);
	else if (!(cheapest_node->over_median)
		&& !(cheapest_node->target->over_median))
		rotate_both (a, b, cheapest_node, true);
	bring_node_to_top (a, cheapest_node, 'a');
	bring_node_to_top (b, cheapest_node->target, 'b');
	pb (b, a);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->n != find_min(*a)->n)
	{
		if (find_min(*a)->over_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = lenght_of_stack(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb (b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb (b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		handle_nodes_a (*a, *b);
		move_a_to_b (a, b);
	}
	tiny_sort (a);
	while (*b)
	{
		set_position (*a);
		set_position (*b);
		set_target_b (*a, *b);
		bring_node_to_top (a, (*b)->target, 'a');
		pa (a, b);
	}
	min_on_top (a);
}
