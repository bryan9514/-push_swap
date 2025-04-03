/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:53:22 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/18 12:38:54 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int ac, char **av)
{
	char	**args;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (NULL);
	}
	else
		args = av + 1;
	return (args);
}
void	validate_and_parse_args(int ac, char **av, t_stack **a_stack)
{
	char	**args;

	args = get_args(ac, av);
	if (!args || !validate_args(args))
	{
		write (1, "Error\n", 6);
		if (ac == 2)
			free_args(args);
		exit (1);
	}
	*a_stack = init_stack(args);
	if (ac == 2)
		free_args(args);
}


//Esta funcion por borrar
void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	tmp = stack;
	while (tmp)
	{
		ft_printf ("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}


int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac == 1 || (ac == 2 && !*av[1]))
		return (0);

	validate_and_parse_args(ac, av, &a_stack);
	choose_sorting_algo(&a_stack, &b_stack);
	//print_stack(a_stack);
	free_stack(&a_stack);
	return (0);
}

