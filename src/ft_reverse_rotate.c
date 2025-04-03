/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:54:00 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/06 17:15:11 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penul;

	if (!*stack || !(*stack)->next)
		return ;
	penul = *stack;
	while (penul->next->next != NULL)
		penul = penul->next;

	last = penul->next;
	penul->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_stack **a_stack)
{
	ft_reverse_rotate(a_stack);
	ft_printf ("rra\n");
}

void	ft_rrb(t_stack **b_stack)
{
	ft_reverse_rotate(b_stack);
	ft_printf ("rrb\n");
}

void	ft_rrr(t_stack **a_stack, t_stack **b_stack)
{
	ft_reverse_rotate(a_stack);
	ft_reverse_rotate(b_stack);
	ft_printf ("rrr\n");
}
