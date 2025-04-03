/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:41:17 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/03 14:22:58 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a_stack)
{
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
		min_on_top(a_stack);
		ft_pb(a_stack, b_stack);
	}
	sort_three(a_stack);
	ft_pa(a_stack, b_stack);
	ft_pa(a_stack, b_stack);
}
