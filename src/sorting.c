/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:41:17 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/11 12:33:39 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a_stack)
{
	// 2 1
	if ((*a_stack)->value > (*a_stack)->next->value)
		ft_sa(a_stack);
}

void	sort_three(t_stack **a_stack)
{
	if ((*a_stack)->value > (*a_stack)->next->value
		&& (*a_stack)->next->value > (*a_stack)->next->next->value)
	{
		ft_sa(a_stack);
		ft_rra(a_stack);
	}
	else if ((*a_stack)->value > (*a_stack)->next->value
		&& (*a_stack)->value > (*a_stack)->next->next->value)
		ft_ra(a_stack);
	else if ((*a_stack)->value > (*a_stack)->next->value)
		ft_sa(a_stack);
	else if ((*a_stack)->value < (*a_stack)->next->next->value
		&& (*a_stack)->next->value > (*a_stack)->next->next->value)
	{
		ft_sa(a_stack);
		ft_ra(a_stack);
	}
	else if ((*a_stack)->value < (*a_stack)->next->value
		&& (*a_stack)->next->value > (*a_stack)->next->next->value)
		ft_rra(a_stack);
}

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
	return (-1); // Este caso no debería ocurrir si target existe en stack
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
			ft_ra(a_stack); // rota hacia arriba
	}
	else
	{
		while ((*a_stack)->value != min->value)
			ft_rra(a_stack); // rotación inversa
	}
}

void	sort_four(t_stack **a_stack, t_stack **b_stack)
{
	while (size_stack(*a_stack) > 3)
	{
		min_on_top(a_stack);
		ft_pb(a_stack, b_stack);
	}
	sort_three(a_stack);
	ft_pa(a_stack, b_stack);
}

void	sort_five(t_stack **a_stack, t_stack **b_stack)
{
	while (size_stack(*a_stack) > 3)
	{
		min_on_top(a_stack); // mínimo valor en la cima de 'a'
		ft_pb(a_stack, b_stack); // mover a 'b'
	}
	sort_three(a_stack); // ordena los 3 números restantes en 'a'
	ft_pa(a_stack, b_stack); // mueve el segundo mínimo de vuelta a 'a'
	ft_pa(a_stack, b_stack); // mueve el mínimo de vuelta a 'a'
}
