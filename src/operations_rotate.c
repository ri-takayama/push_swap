/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:47:19 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 13:30:08 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_stack **lst, int print)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	*lst = tmp->next;
	tmp->next = NULL;
	if (print == 1)
		ft_putstr("ra\n");
	else if (print == 2)
		ft_putstr("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((!*stack_a || !(*stack_a)->next) || (!*stack_b || !(*stack_b)->next))
		return ;
	ft_ra_rb(stack_a, 0);
	ft_ra_rb(stack_b, 0);
	ft_putstr("rr\n");
}

void	ft_rra_rrb(t_stack **lst, int print)
{
	t_stack	*tmp;
	int		lstsize;

	if (!*lst || !(*lst)->next)
		return ;
	lstsize = ft_lstsize(*lst);
	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	while (lstsize > 2)
	{
		tmp = tmp->next;
		lstsize--;
	}
	tmp->next = NULL;
	if (print == 1)
		ft_putstr("rra\n");
	else if (print == 2)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((!*stack_a || !(*stack_a)->next) || (!*stack_b || !(*stack_b)->next))
		return ;
	ft_rra_rrb(stack_a, 0);
	ft_rra_rrb(stack_b, 0);
	ft_putstr("rrr\n");
}
