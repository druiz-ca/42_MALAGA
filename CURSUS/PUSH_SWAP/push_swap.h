/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:18:15 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/18 18:49:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void	ft_free(t_stack **stack);
void	ft_error(t_stack **stack_a, t_stack **stack_b);
int		abs(int nb);
void	cost(t_stack **stack_a, t_stack **stack_b);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **a, int *cost);
void	rotate_b(t_stack **b, int *cost);
void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	rev_rotate(t_stack **stack);
void	reverse_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	push_init(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	cheapest_move(t_stack **stack_a, t_stack **stack_b);
int		get_target_pos(t_stack **stack_a, int index_b, int target_i, int trgt);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
void	assign_position(t_stack **stack);
int		get_stack_size(t_stack *stack);
t_stack	*get_before_bottom(t_stack *stack);
t_stack	*get_bottom(t_stack *stack);
int		biggest_index(t_stack *stack);
void	get_position(t_stack **stack);
int		lowest_index_position(t_stack **stack);
int		is_sorted(t_stack *stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_stack(t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_lenght);
void	put_order_index(t_stack *stack_a, int stack_lenght);
int		ft_stack_lenght(t_stack *stack);
int		num_is_repeat(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
void	add_stack(t_stack **stack, t_stack *new_nodo);
t_stack	*new_stack(int value);
int		num_is_ok(char *num);
void	get_numbers(char *av, t_stack **stack_a);
int		main(int argc, char **argv);
