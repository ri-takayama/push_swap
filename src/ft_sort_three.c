/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:50:38 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 12:20:39 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **lst, int print)
{
	if (!lst || !*lst || ft_lstsize(*lst) != 3)
		return ;
	if (is_sorted_sub(*lst))
	{
		final_sort(lst);
		return ;
	}
	if ((*lst)->num == ft_min(*lst))
	{
		ft_rra_rrb(lst, print);
		ft_sa_sb(lst, print);
	}
	else if ((*lst)->num == ft_max(*lst))
	{
		ft_ra_rb(lst, print);
		if (!is_sorted(*lst))
			ft_sa_sb(lst, print);
	}
	else
	{
		if (ft_lstlast(*lst)->num == ft_max(*lst))
			ft_sa_sb(lst, print);
		else
			ft_rra_rrb(lst, print);
	}
}

void	ft_sort_three_rev(t_stack **lst, int print)
{
	if (!lst || !*lst || ft_lstsize(*lst) != 3)
		return ;
	if ((*lst)->num == ft_min(*lst))
	{
		ft_ra_rb(lst, print);
		if (!is_sorted_rev(*lst))
			ft_sa_sb(lst, print);
	}
	else if ((*lst)->num == ft_max(*lst))
	{
		ft_rra_rrb(lst, print);
		ft_sa_sb(lst, print);
	}
	else
	{
		if (ft_lstlast(*lst)->num == ft_min(*lst))
			ft_sa_sb(lst, print);
		else
			ft_rra_rrb(lst, print);
	}
}
