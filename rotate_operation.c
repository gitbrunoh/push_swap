/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:20:58 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/26 14:21:01 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
}		

void	ra(t_stack_node **a, bool write_flag)
{
	rotate(a);
	if (!write_flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool write_flag)
{
	rotate(b);
	if (!write_flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool write_flag)
{
	rotate(a);
	rotate(b);
	if (!write_flag)
		write(1, "rr\n", 3);
}
