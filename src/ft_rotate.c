/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:25:41 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/04 20:24:12 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	last->next = first;
	first->next = NULL;
}
void	ft_ra(t_stack **a_stack)
{
	ft_rotate(a_stack);
	ft_printf("ra\n");
}
void	ft_rb(t_stack **b_stack)
{
	ft_rotate(b_stack);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a_stack, t_stack **b_stack)
{
	ft_rotate(a_stack);
	ft_rotate(b_stack);
	ft_printf("rr\n");
}
