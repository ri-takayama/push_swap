/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:29:54 by rinka             #+#    #+#             */
/*   Updated: 2025/07/19 16:36:48 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_special_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	if (!ft_isint(nptr))
		return (123451234512345);
	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

static t_stack	*create_stack_a(char **args, int is_original)
{
	t_stack	*stack_a;
	size_t	n;
	int		i;

	i = is_original;
	stack_a = NULL;
	while (args[i])
	{
		n = ft_special_atoi(args[i]);
		if (n == 123451234512345 || ft_isduplicate(n, stack_a)
			|| !ft_add_back(&stack_a, ft_new_stack(n)))
		{
			if (!is_original)
				ft_free_args(args);
			if (stack_a)
				ft_free_lst(&stack_a);
			print_error();
		}
		i++;
	}
	return (stack_a);
}

t_stack	*handle_args(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**args_split;

	stack_a = NULL;
	args_split = NULL;
	if (argc < 2)
		print_error();
	if (argc == 2)
	{
		args_split = ft_split(argv[1], ' ');
		stack_a = create_stack_a(args_split, 0);
		ft_free_args(args_split);
	}
	else
	{
		stack_a = create_stack_a(argv, 1);
	}
	return (stack_a);
}
