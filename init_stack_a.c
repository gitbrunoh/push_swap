/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:03:09 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/29 16:03:13 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **a, int n)
{
	t_stack_node	*new;
	t_stack_node	*last_node;

	if (!a)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->cheapest = false;
	new->next = NULL;
	new->n = n;
	if (!(*a))
		*a = new;
	else
	{
		last_node = find_last(*a);
		last_node->next = new;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_check(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (duplicates_check(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
