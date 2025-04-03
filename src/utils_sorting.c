/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:22:49 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/03 14:35:31 by brturcio         ###   ########.fr       */
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
