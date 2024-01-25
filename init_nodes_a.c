#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int	i;
	int	median;
	int	len;

	i = 0;
	if (!stack)
		return ;
	len = lenght_of_stack(stack);
	if (len % 2 != 0)
		median = len / 2 + 1;
	else
		median = len / 2 + 0.5;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->over_median = true;
		else
			stack->over_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_smallest;

	while (a)
	{
		closest_smallest = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->n < a->n 
				&& current_b->n > closest_smallest)
			{
				closest_smallest = current_b->n;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smallest == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	set_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lenght_of_stack(a);
	len_b = lenght_of_stack(b);
	while (a)
	{
		a->cost = a->position; //Definir inicialmente o custo como sendo o índice do nó
		if (!(a->over_median)) //Está abaixo da mediana? Se sim:
			a->cost = len_a - (a->position);
		if (a->target->over_median) //Se o target de `a` estiver acima da mediana:
			a->cost += a->target->position;
		else //If `a` node is indeed above median and its target `b` node is below median
			a->cost += len_b - (a->target->position);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_cost;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost; //Se sim, atualizar o valor de cheapest_value
			cheapest_node = stack; //tbm definir (atulizar) o nó mais barato (pode ser o closest smallest ou closest biggesst)
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) 
{
	set_position(a);
	set_position(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}