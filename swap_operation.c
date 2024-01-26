/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:21:24 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/26 14:21:26 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head) //Define a function that swaps the positions of the top node and second node of a stack
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->previous->previous = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*head)->previous->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->previous = (*head)->previous; //If so, update its `prev` pointer to point back to the `new head`
	(*head)->next = (*head)->previous; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->previous = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

void	sa(t_stack_node	**a, bool write_flag) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (!write_flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool write_flag) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (!write_flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool write_flag) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (!write_flag)
		write(1, "ss\n", 3);
}
