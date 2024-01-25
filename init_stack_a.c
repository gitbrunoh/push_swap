#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
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

static void	append_node(t_stack_node **stack, int n) //Define a function that searches for the last node to append to the linked list
{
	t_stack_node	*node; //To store a pointer to the new node to be created with the value `n`
	t_stack_node	*last_node; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); //Allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->n = n; //Set the `next` data of of the new node to `n` value
	if (!(*stack)) //Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*stack = node; //If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
		node->previous = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node = find_last(*stack); //In which case, find the last node
		last_node->next = node; //Append the new node to the last node
		node->previous = last_node; //Update the previous pointer of the new node and complete the appending
	}
}

void	init_stack_a(t_stack_node **a, char **argv) 
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a); 
		append_node(a, (int)n);
		i++;
	}
}