/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:56:09 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/11 16:21:51 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//(Funciones de manipulación de la pila)
#include "push_swap.h"

t_stack	*init_stack(char **args)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (args[i])
	{
		if (!push_node(&stack, ft_atol(args[i])))
		{
			free_stack_error(&stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

int	push_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value; // asignamos el numero al nodo
	new_node->index = -1;
	new_node->next = NULL;   // apuntamos el next a null
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	return (1);
}


