/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:19:44 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/18 12:25:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	ft_pa(t_stack **a_stack, t_stack **b_stack)
{
	ft_push(a_stack, b_stack);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **a_stack, t_stack **b_stack)
{
	ft_push(b_stack, a_stack);
	ft_printf("pb\n");
}


