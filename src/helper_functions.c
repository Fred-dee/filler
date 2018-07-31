/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:16:20 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/30 10:16:38 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		last_index_of(char const *s, char c)
{
	int i;
	int	ret;

	i = 0;
	ret = -1;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				ret = i;
			i++;
		}
		if (s[i] == c)
			return (i);
	}
	return (ret);
}

double	sum_dblarr(double *arr, size_t size)
{
	double	ret;
	size_t	count;

	count = 0;
	ret = 0;
	while (count < size)
		ret += arr[count++];
	return (ret);
}

size_t	calc_eval(char **board, t_map *map, double *weights, double *init_eval)
{
	size_t ret;

	ret = (size_t)(
			eval_board_right(board, map->pc, map->y_len) *
			weights[0]) + sum_dblarr(init_eval, 4);
	ret += (size_t)(eval_board_left(board, map->pc, map->y_len) *
		weights[1]) + sum_dblarr(init_eval, 4);
	ret += (size_t)(eval_board_up(board, map->pc, map->y_len, map->x_len) *
		weights[2]) + sum_dblarr(init_eval, 4);
	ret += (size_t)(eval_board_down(board, map->pc, map->y_len, map->x_len) *
		weights[3]) + sum_dblarr(init_eval, 4);
	return (ret);
}
