/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:41:56 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 18:15:01 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	int			a_size;
	t_operation	ope;

	a_size = ft_lstsize(*stack_a);
	if (a_size > 6)
	{
		ft_pb(stack_a, stack_b, 2);
		ft_pb(stack_a, stack_b, 2);
		ft_pb(stack_a, stack_b, 2);
		a_size -= 3;
		if (!is_sorted_rev(*stack_b))
			ft_sort_three_rev(stack_b, 2);
		while (a_size > 3)
		{
			ope = get_best_operation_pb(*stack_a, *stack_b);
			run_operations_pb(stack_a, stack_b, ope);
			a_size--;
		}
	}
	else
	{
		while (a_size-- > 3)
			ft_pb(stack_a, stack_b, 2);
	}
}

static void	ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_operation	ope;

	if (!stack_a || !*stack_a || ft_lstsize(*stack_a) != 3)
	{
		if (stack_a)
			ft_free_lst(stack_a);
		if (stack_b)
			ft_free_lst(stack_b);
		print_error();
	}
	if (!is_sorted(*stack_a))
		ft_sort_three(stack_a, 1);
	while (*stack_b)
	{
		ope = get_best_operation_pa(*stack_a, *stack_b);
		run_operations_pa(stack_a, stack_b, ope);
	}
}

void	final_sort(t_stack **stack_a)
{
	int	min_index;

	if (is_sorted(*stack_a))
		return ;
	min_index = ft_get_index(*stack_a, ft_min(*stack_a));
	if ((ft_lstsize(*stack_a) - min_index) > min_index)
	{
		while (min_index > 0)
		{
			ft_ra_rb(stack_a, 1);
			min_index--;
		}
	}
	else
	{
		min_index = (ft_lstsize(*stack_a) - min_index);
		while (min_index > 0)
		{
			ft_rra_rrb(stack_a, 1);
			min_index--;
		}
	}
}

static void	ft_sort_few_args(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			ft_ra_rb(stack_a, 1);
		return ;
	}
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a, 1);
	else if (ft_lstsize(*stack_a) <= 6)
	{
		while (ft_lstsize(*stack_a) != 3)
			ft_pb(stack_a, stack_b, 2);
		if (ft_lstsize(*stack_b) == 2 && !is_sorted_rev(*stack_b))
			ft_ra_rb(stack_b, 2);
		if (ft_lstsize(*stack_b) == 3)
		{
			if (!is_sorted_rev(*stack_b))
				ft_sort_three_rev(stack_b, 2);
		}
		ft_sort_a(stack_a, stack_b);
		final_sort(stack_a);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		print_error();
	if (is_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) <= 6)
		ft_sort_few_args(stack_a, stack_b);
	else
	{
		if (!is_sorted_sub(*stack_a))
		{
			ft_sort_b(stack_a, stack_b);
			ft_sort_a(stack_a, stack_b);
		}
		final_sort(stack_a);
	}
}
