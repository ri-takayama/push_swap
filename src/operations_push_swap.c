/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:53:51 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 15:55:02 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_a || !*stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
	if (print == 1)
		ft_putstr("pa\n");
	else if (print == 2)
		ft_putstr("pb\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if ((!*stack_a || !(*stack_a)->next))
		print_error();
	if (!*stack_b)
	{
		tmp = (*stack_a)->next;
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
		*stack_a = tmp;
		ft_putstr("pb\n");
	}
	else
	{
		ft_pa(stack_b, stack_a, print);
	}
}

void	ft_sa_sb(t_stack **lst, int print)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (print == 1)
		ft_putstr("sa\n");
	else if (print == 2)
		ft_putstr("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((!*stack_a || !(*stack_a)->next) || (!*stack_b || !(*stack_b)->next))
		return ;
	ft_sa_sb(stack_a, 0);
	ft_sa_sb(stack_b, 0);
	ft_putstr("rr\n");
}
