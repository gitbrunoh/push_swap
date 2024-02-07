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

static t_stack_node *find_before_last(t_stack_node *stack)
{
    if (!stack || !stack->next)
        return NULL;
    while (stack->next->next)
        stack = stack->next;
    return stack;
}

static void	rev_rotate(t_stack_node **stack)
{
    t_stack_node	*last_node;
    t_stack_node	*prev_node;

    if (!*stack || !(*stack)->next)
        return ;
    last_node = find_last(*stack);
    prev_node = find_before_last(*stack);
    prev_node->next = NULL;
    last_node->next = *stack;
    *stack = last_node;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
