/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:41:39 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/29 16:41:42 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->n > b->n 
				&& current_a->n < closest_bigger)
			{
				closest_bigger = current_a->n;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_b(a, b);
}
