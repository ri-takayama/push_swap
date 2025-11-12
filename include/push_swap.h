/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:07:49 by rinka             #+#    #+#             */
/*   Updated: 2025/07/26 14:29:22 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_operation
{
	int	type;
	int	count;
	int	push_num;
}	t_operation;

//is_sorted
int			is_sorted(t_stack *stack_a);
int			is_sorted_rev(t_stack *stack_b);
int			is_sorted_sub(t_stack *stack_a);

void		print_error(void);

t_stack		*handle_args(int argc, char *argv[]);

//ft_sort_three
void		ft_sort_three(t_stack **lst, int print);
void		ft_sort_three_rev(t_stack **lst, int print);

//ft_sort
void		final_sort(t_stack **stack_a);
void		ft_sort(t_stack **stack_a, t_stack **stack_b);

//ft_free
void		ft_free_lst(t_stack **lst);
void		ft_free_args(char **args);

//ft_utils1
int			ft_isspace(int c);
int			ft_issign(int c);
int			ft_min(t_stack *lst);
int			ft_max(t_stack *lst);
void		ft_putstr(char *s);

//ft_utils2
int			ft_get_index(t_stack *lst, int n);
int			get_right_place_a(t_stack *stack_a, int n);
int			get_right_place_b(t_stack *stack_b, int n);

//ft_utils3
t_stack		*ft_new_stack(int n);
int			ft_add_back(t_stack **lst, t_stack *node);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);

//check_args_utils
int			check_args_format(char *argv[]);
int			ft_isint(const char *nptr);
int			ft_isduplicate(int n, t_stack *stack_a);

//count operation
int			count_r_r(int index, int place);
int			count_rr_r(int index_size, int index, int place);
int			count_r_rr(int place_size, int index, int place);
int			count_rr_rr(int index_size, int place_size, int index, int place);

//get_best_operation
t_operation	get_best_operation_pa(t_stack *stack_a, t_stack *stack_b);
t_operation	get_best_operation_pb(t_stack *stack_a, t_stack *stack_b);

//run operations
void		run_operations_pa(
				t_stack **stack_a, t_stack **stack_b, t_operation ope);
void		run_operations_pb(
				t_stack **stack_a, t_stack **stack_b, t_operation ope);

//operations_rotate
void		ft_ra_rb(t_stack **lst, int print);
void		ft_rra_rrb(t_stack **lst, int print);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);

//operations_push_swap
void		ft_sa_sb(t_stack **lst, int print);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b, int print);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int print);

#endif
