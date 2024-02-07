/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:47 by brunhenr          #+#    #+#             */
/*   Updated: 2024/02/06 15:27:31 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				mode;

	a = NULL;
	b = NULL;
	mode = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
	{
		argv = ft_splitpush(argv[1]);
		mode = 1;
	}
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (lenght_of_stack(a) == 2)
			sa(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
	free_argv(argv, mode);
	return (0);
}
