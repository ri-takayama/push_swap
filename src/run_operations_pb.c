/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:48:51 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 13:17:31 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_r_r_pb(
		t_stack **stack_a, t_stack **stack_b, int a_index, int b_place)
{
	while (b_place > 0 && a_index > 0)
	{
		ft_rr(stack_a, stack_b);
		b_place--;
		a_index--;
	}
	while (b_place > 0)
	{
		ft_ra_rb(stack_b, 2);
		b_place--;
	}
	while (a_index > 0)
	{
		ft_ra_rb(stack_a, 1);
		a_index--;
	}
}

void	run_rr_r_pb(
		t_stack **stack_a, t_stack **stack_b, int a_index, int b_place)
{
	b_place = ft_lstsize(*stack_b) - b_place;
	while (b_place > 0)
	{
		ft_rra_rrb(stack_b, 2);
		b_place--;
	}
	while (a_index > 0)
	{
		ft_ra_rb(stack_a, 1);
		a_index--;
	}
}

void	run_r_rr_pb(
		t_stack **stack_a, t_stack **stack_b, int a_index, int b_place)
{
	a_index = ft_lstsize(*stack_a) - a_index;
	while (b_place > 0)
	{
		ft_ra_rb(stack_b, 2);
		b_place--;
	}
	while (a_index > 0)
	{
		ft_rra_rrb(stack_a, 1);
		a_index--;
	}
}

void	run_rr_rr_pb(
		t_stack **stack_a, t_stack **stack_b, int a_index, int b_place)
{
	a_index = ft_lstsize(*stack_a) - a_index;
	b_place = ft_lstsize(*stack_b) - b_place;
	while (b_place > 0 && a_index > 0)
	{
		ft_rrr(stack_a, stack_b);
		b_place--;
		a_index--;
	}
	while (b_place > 0)
	{
		ft_rra_rrb(stack_b, 2);
		b_place--;
	}
	while (a_index > 0)
	{
		ft_rra_rrb(stack_a, 1);
		a_index--;
	}
}

void	run_operations_pb(
		t_stack **stack_a, t_stack **stack_b, t_operation ope)
{
	int	a_index;
	int	b_place;

	a_index = ft_get_index(*stack_a, ope.push_num);
	b_place = get_right_place_b(*stack_b, ope.push_num);
	if (ope.type == 1)
		run_r_r_pb(stack_a, stack_b, a_index, b_place);
	if (ope.type == 2)
		run_rr_r_pb(stack_a, stack_b, a_index, b_place);
	if (ope.type == 3)
		run_r_rr_pb(stack_a, stack_b, a_index, b_place);
	if (ope.type == 4)
		run_rr_rr_pb(stack_a, stack_b, a_index, b_place);
	ft_pb(stack_a, stack_b, 2);
}
