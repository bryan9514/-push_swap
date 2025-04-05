/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:40:29 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/05 09:02:46 by brturcio         ###   ########.fr       */
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
