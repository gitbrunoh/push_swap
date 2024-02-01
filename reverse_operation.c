/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:21:12 by brunhenr          #+#    #+#             */
/*   Updated: 2024/02/01 17:19:12 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->previous->next = NULL;
	last_node->next = *stack;
	last_node->previous = NULL;
	*stack = last_node;
	last_node->next->previous = last_node;
}

void	rrb(t_stack_node **b, bool write_flag)
{
	rev_rotate(b);
	if (!write_flag)
		write(1, "rrb\n", 4);
}

void	rra(t_stack_node **a, bool write_flag)
{
	rev_rotate(a);
	if (!write_flag)
		write(1, "rra\n", 4);
}
void	rrr(t_stack_node **a, t_stack_node **b, bool write_flag)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!write_flag)
		write(1, "rrr\n", 4);
}
