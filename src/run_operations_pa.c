/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_pa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:19:31 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 13:18:12 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_r_r_pa(
		t_stack **stack_a, t_stack **stack_b, int b_index, int a_place)
{
	while (a_place > 0 && b_index > 0)
	{
		ft_rr(stack_a, stack_b);
		a_place--;
		b_index--;
	}
	while (a_place > 0)
	{
		ft_ra_rb(stack_a, 1);
		a_place--;
	}
	while (b_index > 0)
	{
		ft_ra_rb(stack_b, 2);
		b_index--;
	}
}

void	run_rr_r_pa(
		t_stack **stack_a, t_stack **stack_b, int b_index, int a_place)
{
	a_place = ft_lstsize(*stack_a) - a_place;
	while (a_place > 0)
	{
		ft_rra_rrb(stack_a, 1);
		a_place--;
	}
	while (b_index > 0)
	{
		ft_ra_rb(stack_b, 2);
		b_index--;
	}
}

void	run_r_rr_pa(
		t_stack **stack_a, t_stack **stack_b, int b_index, int a_place)
{
	b_index = ft_lstsize(*stack_b) - b_index;
	while (a_place > 0)
	{
		ft_ra_rb(stack_a, 1);
		a_place--;
	}
	while (b_index > 0)
	{
		ft_rra_rrb(stack_b, 2);
		b_index--;
	}
}

void	run_rr_rr_pa(
		t_stack **stack_a, t_stack **stack_b, int b_index, int a_place)
{
	b_index = ft_lstsize(*stack_b) - b_index;
	a_place = ft_lstsize(*stack_a) - a_place;
	while (a_place > 0 && b_index > 0)
	{
		ft_rr(stack_a, stack_b);
		a_place--;
		b_index--;
	}
	while (a_place > 0)
	{
		ft_ra_rb(stack_a, 1);
		a_place--;
	}
	while (b_index > 0)
	{
		ft_ra_rb(stack_b, 2);
		b_index--;
	}
}

void	run_operations_pa(
		t_stack **stack_a, t_stack **stack_b, t_operation ope)
{
	int	b_index;
	int	a_place;

	b_index = ft_get_index(*stack_b, ope.push_num);
	a_place = get_right_place_a(*stack_a, ope.push_num);
	if (ope.type == 1)
		run_r_r_pa(stack_a, stack_b, b_index, a_place);
	if (ope.type == 2)
		run_r_rr_pa(stack_a, stack_b, b_index, a_place);
	if (ope.type == 3)
		run_rr_r_pa(stack_a, stack_b, b_index, a_place);
	if (ope.type == 4)
		run_rr_rr_pa(stack_a, stack_b, b_index, a_place);
	ft_pa(stack_a, stack_b, 1);
}
