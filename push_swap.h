#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int						n;
	int						position;
	int						cost;
	bool					over_median;
	bool					cheapest;
	struct s_stack_node		*next;
	struct s_stack_node		*previous;
	struct s_stack_node		*target;
}					t_stack_node;
//Errors
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

//Initiation
void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);

//Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			set_position(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

//***Stack utils
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//Operations (subject)
void			sa(t_stack_node **a, bool write_flag);
void			sb(t_stack_node **b, bool write_flag);
void			ss(t_stack_node **a, t_stack_node **b, bool write_flag);
void			ra(t_stack_node **a, bool write_flag);
void			rb(t_stack_node **b, bool write_flag);
void			rr(t_stack_node **a, t_stack_node **b, bool write_flag);
void			rra(t_stack_node **a, bool write_flag);
void			rrb(t_stack_node **b, bool write_flag);
void			rrr(t_stack_node **a, t_stack_node **b, bool write_flag);
void			pa(t_stack_node **a, t_stack_node **b, bool write_flag);
void			pb(t_stack_node **b, t_stack_node **a, bool write_flag);
//Sorting
void			tiny_sort(t_stack_node **a);
void			sort(t_stack_node **a, t_stack_node **b);

#endif
