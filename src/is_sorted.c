/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:57:14 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 13:09:42 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_sub(t_stack *stack_a)
{
	t_stack	*tmp;
	int		last_num;

	tmp = stack_a;
	last_num = tmp->num;
	if (is_sorted(stack_a))
		return (1);
	if (ft_lstlast(stack_a)->num > tmp->num)
		return (0);
	while (tmp)
	{
		if (last_num > tmp->num && last_num != ft_max(stack_a))
			return (0);
		last_num = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*tmp;
	int		last_num;

	tmp = stack_a;
	last_num = tmp->num;
	while (tmp)
	{
		if (last_num > tmp->num)
			return (0);
		last_num = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted_rev(t_stack *stack_b)
{
	t_stack	*tmp;
	int		last_num;

	tmp = stack_b;
	last_num = tmp->num;
	while (tmp)
	{
		if (last_num < tmp->num)
			return (0);
		last_num = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}
