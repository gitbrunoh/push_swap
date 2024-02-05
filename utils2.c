/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:06 by brunhenr          #+#    #+#             */
/*   Updated: 2024/02/05 16:51:18 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_n(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min_n(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->n > (*a)->next->n)
		sa(a);
}
