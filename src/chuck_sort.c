/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chuck_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:24:50 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/02 17:51:21 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void chunk_to_b(t_stack **a_stack, t_stack **b_stack, int chunk_size)
{
	int current_chunk = chunk_size;

	while (*a_stack)
	{
		if ((*a_stack)->index < current_chunk)
		{
			ft_pb(a_stack, b_stack);

		// Solo rotamos si el número es menor al promedio del chunk
		if ((*b_stack)->index < current_chunk - chunk_size / 2)
			ft_rb(b_stack);
		}
		else
		{
			ft_ra(a_stack);
		}

		// Ajustamos el tamaño del chunk dinámicamente
		if (size_stack(*b_stack) >= current_chunk)
			current_chunk += chunk_size;
		}
}

t_stack *find_max(t_stack *stack)
{
	if (!stack) // ← Evita segfault si `stack` está vacío
		return NULL;

	t_stack *max_node = stack;
	while (stack)
	{
		if (stack->index > max_node->index)
			max_node = stack;
			stack = stack->next;
		}
	return max_node;
}



void move_chunks_to_a(t_stack **a_stack, t_stack **b_stack)
{
	t_stack *max_node;
	int pos, len;

	while (*b_stack)
	{
		max_node = find_max(*b_stack);
		pos = get_position(*b_stack, max_node);
		len = size_stack(*b_stack);

		// Optimización: Evitar rotar `stack_a` si no es necesario
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


// función asignación de índices claramente corregida:
void assign_index(t_stack *stack)
{
	t_stack *current;
	t_stack *min_node;
	int index = 0;
	int total_size = size_stack(stack); // ← Guardar tamaño fijo para evitar problemas

	while (index < total_size)
	{
		current = stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1 && (!min_node || current->value < min_node->value))
			min_node = current;
			current = current->next;
		}
		if (min_node)
			min_node->index = index++;
	}
}
// resto de funciones...





void chunk_sort(t_stack **a_stack, t_stack **b_stack)
{
	int len = size_stack(*a_stack);
	int chunk_size;

	if (len <= 100)
		chunk_size = len / 5;  // 5 chunks
	else if (len <= 500)
		chunk_size = len / 10; // 10 chunks
	else
		chunk_size = len / 8;  // 8 chunks para +500 números

	if (!*a_stack) return; // ← Evita fallos si `a_stack` está vacío

	chunk_to_b(a_stack, b_stack, chunk_size);
	move_chunks_to_a(a_stack, b_stack);
}
