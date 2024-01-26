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

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next) //Checar se existe um head e um segundo nó
		return ;
	*head = (*head)->next; 
	(*head)->previous->previous = *head; //O previous do antigo head passa a ser o novo head
	(*head)->previous->next = (*head)->next; //O next do antigo head passa a ser o antigo next do novo head
	if ((*head)->next) //Chechar se existe um terceiro nó 
		(*head)->next->previous = (*head)->previous; //Se sim, bora ligar os fios do terceiro nó
	(*head)->next = (*head)->previous; 
	(*head)->previous = NULL;
}

void	sa(t_stack_node	**a, bool write_flag)
{
	swap(a);
	if (!write_flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool write_flag)
{
	swap(b);
	if (!write_flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool write_flag)
{
	swap(a);
	swap(b);
	if (!write_flag)
		write(1, "ss\n", 3);
}
