/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinka <rinka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:21:02 by rinka             #+#    #+#             */
/*   Updated: 2025/06/09 18:54:35 by rinka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rarb = 1
rrarb = 2
rarrb = 3
// rrarrb = 4*/

static void	set_ope(t_operation *ope, int count, int type, int push_num)
{
	ope->count = count;
	ope->type = type;
	ope->push_num = push_num;
}

static void	iter_count_a(t_stack *tmp,
		t_operation *best_operation, t_stack *stack_a, t_stack *stack_b)
{
	int			b_index;
	int			a_place;

	b_index = ft_get_index(stack_b, tmp->num);
	a_place = get_right_place_a(stack_a, tmp->num);
	if (best_operation->count > count_r_r(b_index, a_place))
		set_ope(best_operation, count_r_r(b_index, a_place), 1, tmp->num);
	if (best_operation->count > count_rr_r(
			ft_lstsize(stack_b), b_index, a_place))
		set_ope(best_operation, count_rr_r(
				ft_lstsize(stack_b), b_index, a_place), 2, tmp->num);
	if (best_operation->count > count_r_rr(
			ft_lstsize(stack_a), b_index, a_place))
		set_ope(best_operation, count_r_rr(
				ft_lstsize(stack_a), b_index, a_place), 3, tmp->num);
	if (best_operation->count > count_rr_rr(
			ft_lstsize(stack_b), ft_lstsize(stack_a), b_index, a_place))
		set_ope(best_operation, count_rr_rr(ft_lstsize(stack_b),
				ft_lstsize(stack_a), b_index, a_place), 4, tmp->num);
}

t_operation	get_best_operation_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*tmp;
	t_operation	best_operation;

	tmp = stack_b;
	set_ope(&best_operation, INT_MAX, 1, tmp->num);
	while (tmp)
	{
		iter_count_a(tmp, &best_operation, stack_a, stack_b);
		tmp = tmp->next;
	}
	return (best_operation);
}

static void	iter_count_b(t_stack *tmp,
		t_operation *best_operation, t_stack *stack_a, t_stack *stack_b)
{
	int			a_index;
	int			b_place;

	a_index = ft_get_index(stack_a, tmp->num);
	b_place = get_right_place_b(stack_b, tmp->num);
	if (best_operation->count > count_r_r(a_index, b_place))
		set_ope(best_operation, count_r_r(
				a_index, b_place), 1, tmp->num);
	if (best_operation->count > count_rr_r(
			ft_lstsize(stack_b), b_place, a_index))
		set_ope(best_operation, count_rr_r(
				ft_lstsize(stack_b), b_place, a_index), 2, tmp->num);
	if (best_operation->count > count_r_rr(
			ft_lstsize(stack_a), b_place, a_index))
		set_ope(best_operation, count_r_rr(
				ft_lstsize(stack_a), b_place, a_index), 3, tmp->num);
	if (best_operation->count > count_rr_rr(
			ft_lstsize(stack_a), ft_lstsize(stack_b), a_index, b_place))
		set_ope(best_operation, count_rr_rr(ft_lstsize(stack_a),
				ft_lstsize(stack_b), a_index, b_place), 4, tmp->num);
}

t_operation	get_best_operation_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*tmp;
	t_operation	best_operation;

	tmp = stack_a;
	set_ope(&best_operation, INT_MAX, 1, tmp->num);
	while (tmp)
	{
		iter_count_b(tmp, &best_operation, stack_a, stack_b);
		tmp = tmp->next;
	}
	return (best_operation);
}
