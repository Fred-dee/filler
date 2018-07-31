/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:36:10 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/18 14:36:11 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		init_board(char ***b, int y_len, int x_len)
{
	int x;

	if ((b[0] = (char **)malloc(sizeof(char *) * y_len)) == NULL)
		return (-1);
	x = 0;
	while (x < y_len)
		b[0][x++] = (char *)malloc(sizeof(char) * x_len);
	return (0);
}

void	place_piece(char **b, t_move *mv, t_map *map, t_piece *piece)
{
	int	i;
	int	j;

	i = mv->y;
	while (i - mv->y < piece->y_len)
	{
		j = mv->x;
		while (j - mv->x < piece->x_len)
		{
			if (piece->shape[i - mv->y][j - mv->x] == '*')
				b[i][j] = map->pc;
			j++;
		}
		i++;
	}
}

void	copy_board(char **ret, char **map, int y_len)
{
	int		i;

	i = 0;
	while (i < y_len)
	{
		ft_strcpy(ret[i], map[i]);
		i++;
	}
}

void	set_weight_init(double init_eval[4], double weights[4], t_map *map)
{
	if (ft_tolower(map->pc) == 'o')
	{
		weights[0] = 0.45;
		weights[1] = 0.05;
		weights[2] = 0.20;
		weights[3] = 0.30;
	}
	else
	{
		weights[0] = 0.05;
		weights[1] = 0.30;
		weights[2] = 0.50;
		weights[3] = 0.15;
	}
	init_eval[0] = (int)(eval_board_right(map->matrix,
		map->pc, map->y_len) * weights[0]);
	init_eval[1] = (int)(eval_board_left(map->matrix,
		map->pc, map->y_len) * weights[1]);
	init_eval[2] = (int)(eval_board_up(map->matrix,
		map->pc, map->y_len, map->x_len) * weights[2]);
	init_eval[3] = (int)(eval_board_down(map->matrix,
		map->pc, map->y_len, map->x_len) * weights[3]);
}

int		apply_heuristic(t_list **lst, t_map *map, t_piece *piece)
{
	char	**board;
	t_list	*tmp;
	double	weights[4];
	double	init_eval[4];

	set_weight_init(init_eval, weights, map);
	tmp = *lst;
	if (init_board(&board, map->y_len, map->x_len) == -1)
		return (-1);
	while (tmp != NULL)
	{
		copy_board(board, map->matrix, map->y_len);
		place_piece(board, ((t_move *)tmp->content), map, piece);
		tmp->content_size = calc_eval(board, map, weights, init_eval);
		tmp = tmp->next;
	}
	return (0);
}
