/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:52:56 by rinka             #+#    #+#             */
/*   Updated: 2025/07/01 15:42:41 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	ft_min(t_stack *lst)
{
	t_stack	*tmp;
	int		res;

	res = lst->num;
	tmp = lst->next;
	while (tmp)
	{
		if (tmp->num < res)
			res = tmp->num;
		tmp = tmp->next;
	}
	return (res);
}

int	ft_max(t_stack *lst)
{
	t_stack	*tmp;
	int		res;

	res = lst->num;
	tmp = lst->next;
	while (tmp)
	{
		if (tmp->num > res)
			res = tmp->num;
		tmp = tmp->next;
	}
	return (res);
}
