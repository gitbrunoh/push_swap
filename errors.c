/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:19:32 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/31 16:10:07 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_check(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| ft_isdigit(*str_n)))
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(ft_isdigit(*(str_n + 1))))
		return (1);
	while (*++str_n)
	{
		if (!(ft_isdigit(*str_n)))
			return (1);
	}
	return (0);
}

int	duplicates_check(t_stack_node *node_a, int n)
{
	if (!node_a)
		return (0);
	while (node_a)
	{
		if (node_a->n == n)
			return (1);
		node_a = node_a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		current->n = 0;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
