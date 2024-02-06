/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:19:04 by brunhenr          #+#    #+#             */
/*   Updated: 2024/02/06 17:17:10 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenght_of_stack(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (false);
		a = a->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *a)
{
	long			min;
	t_stack_node	*min_node;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->n < min)
		{
			min = a->n;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->n > max)
		{
			max = stack->n;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
