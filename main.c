/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:47 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/26 14:15:49 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		argv = ft_splitpush(argv[1]);
	init_stack_a(&stack_a, argv + 1);
	if (!stack_sorted(stack_a))
	{
		if (lenght_of_stack(stack_a) == 2)
			sa(&stack_a);
		else if (lenght_of_stack(stack_a) == 3)
			tiny_sort(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
