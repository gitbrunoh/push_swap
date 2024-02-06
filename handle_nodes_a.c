/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:41:10 by brunhenr          #+#    #+#             */
/*   Updated: 2024/02/06 17:08:11 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack_node *a)
{
	int	i;
	int	median;
	int	len;

	i = 0;
	if (!a)
		return ;
	len = lenght_of_stack(a);
	if (len % 2 != 0)
		median = len / 2 + 1;
	else
		median = len / 2;
	while (a)
	{
		a->position = i;
		if (i < median)
			a->over_median = true;
		else
			a->over_median = false;
		a = a->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_smaller;

	while (a)
	{
		closest_smaller = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->n < a->n
				&& current_b->n > closest_smaller)
			{
				closest_smaller = current_b->n;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller == LONG_MIN)
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
			a->cost = min_n(pt, (len_b - pt)) + min_n(p, (len_a - p));
		a = a->next;
	}
}

static void	set_cheapest(t_stack_node *a)
{
	long			cheapest_cost;
	t_stack_node	*cheapest_node;

	if (!a)
		return ;
	cheapest_cost = LONG_MAX;
	while (a)
	{
		if (a->cost < cheapest_cost)
		{
			cheapest_cost = a->cost;
			cheapest_node = a;
		}
		a = a->next;
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
