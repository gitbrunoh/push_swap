/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:41:10 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/29 16:41:17 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	set_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	p;
	int	pt;

	len_a = lenght_of_stack(a);
	len_b = lenght_of_stack(b);
	while (a)
	{
		p = a->position;
		pt = a->target->position;
		if (a->target->over_median && a->over_median)
			a->cost = max_n(pt, p);
		else if (!(a->target->over_median) && !(a->over_median))
			a->cost = max_n(len_b - pt, len_a - p);
		else
			a->cost = min_n(p, (len_a - p)) + min_n(pt, (len_b - pt));
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_cost;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	handle_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}
