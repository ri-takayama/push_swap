/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:39:35 by rtakayam          #+#    #+#             */
/*   Updated: 2025/07/01 16:53:00 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_close_num(t_stack *lst, int n)
{
	int				close_num;
	t_stack			*tmp;
	unsigned int	current_gap;
	unsigned int	gap;

	tmp = lst;
	close_num = tmp->num;
	current_gap = UINT_MAX;
	while (tmp)
	{
		if (n > tmp->num)
			gap = n - tmp->num;
		else
			gap = tmp->num - n;
		if (gap < current_gap)
		{
			close_num = tmp->num;
			current_gap = gap;
		}
		tmp = tmp->next;
	}
	return (close_num);
}

int	ft_get_index(t_stack *lst, int n)
{
	int		res;
	t_stack	*tmp;

	tmp = lst;
	res = 0;
	while (tmp)
	{
		if (tmp->num == n)
			break ;
		tmp = tmp->next;
		res++;
	}
	return (res);
}

int	get_right_place_a(t_stack *stack_a, int n)
{
	int	close_num;

	close_num = get_close_num(stack_a, n);
	if (n < close_num)
		return (ft_get_index(stack_a, close_num));
	else
	{
		if (close_num == ft_lstlast(stack_a)->num)
			return (0);
		return (ft_get_index(stack_a, close_num) + 1);
	}
}

int	get_right_place_b(t_stack *stack_b, int n)
{
	int	close_num;

	close_num = get_close_num(stack_b, n);
	if (n > close_num)
		return (ft_get_index(stack_b, close_num));
	else
	{
		if (close_num == ft_lstlast(stack_b)->num)
			return (0);
		return (ft_get_index(stack_b, close_num) + 1);
	}
}
