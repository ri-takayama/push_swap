/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakayam <rtakayam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:15:16 by rtakayam          #+#    #+#             */
/*   Updated: 2025/07/01 15:48:30 by rtakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_r_r(int index, int place)
{
	if (index > place)
		return (index);
	else
		return (place);
}

int	count_rr_r(int index_size, int index, int place)
{
	return ((index_size - index) + place);
}

int	count_r_rr(int place_size, int index, int place)
{
	return (index + (place_size - place));
}

int	count_rr_rr(int index_size, int place_size, int index, int place)
{
	if ((index_size - index) > (place_size - place))
		return (index_size - index);
	else
		return (place_size - place);
}
