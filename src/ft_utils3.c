/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:20:14 by rtakayam          #+#    #+#             */
/*   Updated: 2025/07/19 16:37:04 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int n)
{
	t_stack	*new_node;

	new_node = NULL;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = n;
	new_node->next = NULL;
	return (new_node);
}

int	ft_add_back(t_stack **lst, t_stack *node)
{
	t_stack	*tmp;

	if (node == NULL)
		return (0);
	tmp = NULL;
	if (!*lst)
	{
		*lst = node;
		return (1);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
