/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:29:51 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/10 11:22:56 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_lenght)
{
	if (stack_lenght == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_lenght == 3)
		sort_three(stack_a);
	else if (stack_lenght > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	put_order_index(t_stack *stack_a, int stack_lenght)
{
	t_stack	*ptr;
	t_stack	*ptr_bignode;
	int		max_value;

	while (--stack_lenght > 0)
	{
		ptr = stack_a;
		ptr_bignode = NULL;
		max_value = INT_MIN;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > max_value && ptr->index == 0)
			{
				max_value = ptr->value;
				ptr_bignode = ptr;
				ptr = ptr->next;
			}
			else
				ptr = ptr->next;
		}
		if (ptr_bignode != NULL)
			ptr_bignode->index = stack_lenght;
	}
}

int	ft_stack_lenght(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	num_is_repeat(t_stack *stack_a)
{
	t_stack	*aux1;
	t_stack	*aux2;

	aux1 = stack_a;
	while (aux1)
	{
		aux2 = aux1->next;
		while (aux2)
		{
			if (aux1->value == aux2->value)
				return (1);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
	return (0);
}

t_stack	*get_last_node(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
