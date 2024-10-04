/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:46:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/10 11:26:53 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_target_pos(t_stack **stack_a, int index_b, int target_i, int target)
{
	t_stack	*aux_a;

	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->index > index_b && aux_a->index < target_i)
		{
			target_i = aux_a->index;
			target = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	if (target_i != INT_MAX)
		return (target);
	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->index < target_i)
		{
			target_i = aux_a->index;
			target = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	return (target);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		target;

	target = 0;
	aux_b = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
	while (aux_b)
	{
		target = get_target_pos(stack_a, aux_b->index, INT_MAX, target);
		aux_b->target = target;
		aux_b = aux_b->next;
	}
}

void	assign_position(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = *stack;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
