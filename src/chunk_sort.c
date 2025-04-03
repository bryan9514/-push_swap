/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:40:29 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/03 14:33:37 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_b(t_stack **a_stack, t_stack **b_stack, int chunk_size)
{
	int	current_chunk;

	current_chunk = chunk_size;
	while (*a_stack)
	{
		if ((*a_stack)->index < current_chunk)
		{
			ft_pb(a_stack, b_stack);
			if ((*b_stack)->index < current_chunk - chunk_size / 2)
				ft_rb(b_stack);
		}
		else
		{
			ft_ra(a_stack);
		}
		if (size_stack(*b_stack) >= current_chunk)
			current_chunk += chunk_size;
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

void	move_chunks_to_a(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*max_node;
	int		pos;
	int		len;

	while (*b_stack)
	{
		max_node = find_max(*b_stack);
		pos = get_position(*b_stack, max_node);
		len = size_stack(*b_stack);
		if (pos <= len / 2)
		{
			while (*b_stack != max_node)
				ft_rb(b_stack);
		}
		else
		{
			while (*b_stack != max_node)
				ft_rrb(b_stack);
		}
		ft_pa(a_stack, b_stack);
	}
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

void	chunk_sort(t_stack **a_stack, t_stack **b_stack)
{
	int	len;
	int	chunk_size;

	len = size_stack(*a_stack);
	if (len <= 100)
		chunk_size = len / 5;
	else if (len <= 500)
		chunk_size = len / 10;
	else
		chunk_size = len / 8;
	if (!*a_stack)
		return ;
	chunk_to_b(a_stack, b_stack, chunk_size);
	move_chunks_to_a(a_stack, b_stack);
}
