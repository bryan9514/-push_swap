/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:41:35 by brturcio          #+#    #+#             */
/*   Updated: 2025/03/13 13:04:00 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **args, char *num, int index)
{
	int	i;
	long	number;

	i = 0;
	number = ft_atol(num);
	while (i < index)
	{
		if (ft_atol(args[i]) == number)
			return (0);

		i++;
	}
	return (1);
}

int	is_number(char *args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
		return (0);
	if ((args[i] == '-' || args[i] == '+') && (args[i + 1] >= '0' && args[i + 1] <= '9'))
		i++;
	else if (args[i] == '-' || args[i] == '+') //  Caso como "++4" o "--5"
		return (0);
	while (args[i])
	{
		if (args[i] < '0' || args[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(char **args)
{
	int	i;
	long	num;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		if (!check_duplicate(args, args[i], i))
			return (0);
		i++;
	}
	return (1);
}




