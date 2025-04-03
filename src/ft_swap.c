/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:12:40 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/03 14:19:48 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*segund;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	segund = first->next;
	first->next = segund->next;
	segund->next = first;
	*stack = segund;
}

void	ft_sa(t_stack **a_stack)
{
	ft_swap(a_stack);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b_stack)
{
	ft_swap(b_stack);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a_stack, t_stack **b_stack)
{
	ft_swap(a_stack);
	ft_swap(b_stack);
	ft_printf("ss\n");
}
