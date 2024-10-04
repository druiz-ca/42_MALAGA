/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:14:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/08/10 11:30:55 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_stack(t_stack **stack, t_stack *new_nodo)
{
	t_stack	*last_node;

	if (!new_nodo)
		return ;
	if (*stack == NULL)
	{
		*stack = new_nodo;
		return ;
	}
	last_node = get_last_node(*stack);
	last_node->next = new_nodo;
}

t_stack	*new_stack(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = -1;
	new_node->target = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = NULL;
	return (new_node);
}

int	num_is_ok(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+') && (ft_strlen(num) > 1))
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	get_numbers(char *av, t_stack **stack_a)
{
	char		**matrix;
	long int	value;
	int			i;

	i = 0;
	matrix = ft_split(av, ' ');
	while (matrix[i])
	{
		if (num_is_ok(matrix[i]))
		{
			value = ft_atoi(matrix[i]);
			if (value > INT_MAX || value < INT_MIN)
				ft_error(stack_a, NULL);
			add_stack(stack_a, new_stack(value));
		}
		else
			ft_error(NULL, NULL);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		stack_lenght;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		get_numbers(argv[i], &stack_a);
		i++;
	}
	if (num_is_repeat(stack_a))
		ft_error(&stack_a, NULL);
	stack_lenght = ft_stack_lenght(stack_a);
	put_order_index(stack_a, stack_lenght + 1);
	push_swap(&stack_a, &stack_b, stack_lenght);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
