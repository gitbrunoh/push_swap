#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_box	*stack_a;
	t_stack_box	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 | argc == 2 && argv[1][0] == '\0')
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1); //Verificar erros de entrada e criar o stack a com os numeros
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}