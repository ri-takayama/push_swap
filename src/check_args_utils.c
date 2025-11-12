/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:41:44 by rtakayam          #+#    #+#             */
/*   Updated: 2025/07/26 15:00:46 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args_format(char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_issign(argv[i][j]) &&
					!ft_isspace(argv[i][j]))
				return (0);
			if (ft_issign(argv[i][j]) &&
					((j != 0 && !ft_isspace(argv[i][j - 1])) ||
					(!argv[i][j + 1] || !ft_isdigit(argv[i][j + 1]))))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	over_int(const char *nptr, size_t i)
{
	if (nptr[i - 10] && nptr[i - 10] == '-')
	{
		if (ft_strncmp(&nptr[i - 10], "-2147483648", 11) > 0)
			return (1);
	}
	else if (ft_strncmp(&nptr[i - 9], "2147483647", 10) > 0)
		return (1);
	return (0);
}

int	ft_isint(const char *nptr)
{
	size_t	i;
	size_t	digit_index;

	i = 0;
	digit_index = 0;
	while (!ft_isdigit(nptr[i]))
		i++;
	while (nptr[i] == '0')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		digit_index++;
		if (digit_index == 10)
		{
			if (over_int(nptr, i))
				return (0);
		}
		if (digit_index > 10)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isduplicate(int n, t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->num == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
