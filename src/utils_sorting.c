/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:22:49 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/04 22:13:31 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;

	min_node = stack;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

int	get_position(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	min_on_top(t_stack **a_stack)
{
	t_stack	*min;
	int		pos;
	int		len;

	min = find_min(*a_stack);
	pos = get_position(*a_stack, min);
	len = size_stack(*a_stack);
	if (pos <= len / 2)
	{
		while ((*a_stack)->value != min->value)
			ft_ra(a_stack);
	}
	else
	{
		while ((*a_stack)->value != min->value)
			ft_rra(a_stack);
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->index > max_node->index)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;
	int		index;
	int		total_size;

	index = 0;
	total_size = size_stack(stack);
	while (index < total_size)
	{
		current = stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1 && (!min_node || \
				current->value < min_node->value))
				min_node = current;
			current = current->next;
		}
		if (min_node)
			min_node->index = index++;
	}
}
