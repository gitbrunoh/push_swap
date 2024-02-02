/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:16:48 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/31 15:56:25 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//Utils functions
int				lenght_of_stack(t_stack_node *stack);
int				max_n(int a, int b);
int				min_n(int a, int b);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *a);
t_stack_node	*find_min(t_stack_node *a);
t_stack_node	*find_max(t_stack_node *stack);

//Stack initialization with some errors check
char			**ft_splitpush(char *str);
int				syntax_check(char *str);
int				duplicates_check(t_stack_node *a, int n);
void			free_stack(t_stack_node **a);
void			free_errors(t_stack_node **a);
void			init_stack_a(t_stack_node **a, char **argv);

//Operations (subject)
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

//Algorithm Core
void			set_position(t_stack_node *stack);
void			handle_nodes_a(t_stack_node *a, t_stack_node *b);
void			handle_nodes_b(t_stack_node *a, t_stack_node *b);
void			tiny_sort(t_stack_node **a);
void			sort(t_stack_node **a, t_stack_node **b);

#endif
