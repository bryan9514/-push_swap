/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:21:39 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/06 11:30:28 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	print_stack_reverse(t_stack *stack);

char	**get_args(int ac, char **av);
void	validate_and_parse_args(int ac, char **av, t_stack **a_stack);
void	choose_sorting_algo(t_stack **a_stack, t_stack **b_stack);

int		check_duplicate(char **args, char *num, int index);
int		is_number(char *args);
int		validate_args(char **args);

long	ft_atol(char *str);

t_stack	*init_stack(char **args);
int		push_node(t_stack **stack, int value);

int		check_list_order(t_stack *stack);
int		size_stack(t_stack *stack);

void	free_args(char **args);
void	free_stack(t_stack **stack);
void	free_stack_error(t_stack **stack);

void	sort_two(t_stack **a_stack);
void	sort_three(t_stack **a_stack);
void	sort_five(t_stack **a_stack, t_stack **b_stack);

t_stack	*find_min(t_stack *stack);
int		get_position(t_stack *stack, t_stack *target);
void	min_on_top(t_stack **a_stack);

void	chunk_sort(t_stack **a_stack, t_stack **b_stack);
void	chunk_to_b(t_stack **a_stack, t_stack **b_stack, int chunk_size);
void	move_chunks_to_a(t_stack **a_stack, t_stack **b_stack);
t_stack	*find_max(t_stack *stack);
void	assign_index(t_stack *stack);
t_stack	*find_min_unindexed(t_stack *stack);
void	assign_index(t_stack *stack);

void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **a_stack);
void	ft_sb(t_stack **b_stack);
void	ft_ss(t_stack **a_stack, t_stack **b_stack);

void	ft_push(t_stack **dest, t_stack **src);
void	ft_pa(t_stack **a_stack, t_stack **b_stack);
void	ft_pb(t_stack **a_stack, t_stack **b_stack);

void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **a_stack);
void	ft_rrb(t_stack **b_stack);
void	ft_rrr(t_stack **a_stack, t_stack **b_stack);

void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **a_stack);
void	ft_rb(t_stack **b_stack);
void	ft_rr(t_stack **a_stack, t_stack **b_stack);

#endif
