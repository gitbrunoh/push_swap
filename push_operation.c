/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:20:44 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/26 14:20:46 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; //Armazenar o node que será pushado

	if (!*src) //O top node que será pushado existe?
		return ;
	push_node = *src;
	*src = (*src)->next; 
	if (*src) //Checar se essse next node existe
		(*src)->previous = NULL; //Se sim, ele passa a ser o head, ou seja, tem o previous como NULL
	push_node->previous = NULL; //Detach the node to push from its stack
	if (!*dst)
	{
		*dst = push_node; //Se o outro stack estiver vazio, o node que será pushado passa a ser o head
		push_node->next = NULL; //Assegurar que é o último node da pilha e terminar com NULL
	}
	else  
	{
		push_node->next = *dst; //o Next do novo head de b será o dst, ou seja, o head antigo
		push_node->next->previous = push_node; //Se o next é o head antigo, o previous dele é o novo head
		*dst = push_node; //Agora sim, dando o correto nome aos bois. O push_node é o novo head
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool write_flag)
{
	push(a, b); 
	if (!write_flag) 
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool write_flag)
{
	push(b, a);
	if (!write_flag)
		write(1, "pb\n", 3);
}
