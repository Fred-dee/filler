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
#include <stdio.h>

void	place_piece(char **b, int mx, int my, t_map *map, t_piece *piece)
{
	int	i;
	int	j;

	i = my;
	while (i - my < piece->y_len)
	{
		j = mx;
		while (j - mx < piece->x_len)
		{
			if (piece->shape[i - my][j - mx] == '*')
				b[i][j] = map->pc;
			j++;
		}
		i++;
	}
}

void	copy_board(char **ret, char  **map, int y_len)
{
	int		i;

	i = 0;
	while (i < y_len)
	{
		ft_strcpy(ret[i], map[i]);
		i++;
	}
}


int	apply_heuristic(t_list **lst, t_map *map, t_piece *piece)
{
	char	**board;
	t_list	*tmp;
	//size_t	init_eval;
	t_move	*mv;
	int		my;
	int		mx;
	int		x;
	double	weights[4];
	double	init_eval[4];

	if (ft_tolower(map->pc) == 'o')
	{
		weights[0] = 0.35;
		weights[1] = 0.15;
		weights[2] = 0.15;
		weights[3] = 0.35;
	}
	else
	{
		weights[0] = 0.10;
		weights[1] = 0.20;
		weights[2] = 0.40;
		weights[3] = 0.20;		
	}
	tmp = *lst;
	init_eval[0] = (int) (eval_board_right(map->matrix, map->pc, map->y_len) * weights[0]);
	init_eval[1] = (int) (eval_board_left(map->matrix, map->pc, map->y_len) * weights[1]);
	init_eval[2] = (int) (eval_board_up(map->matrix, map->pc, map->y_len, map->x_len) * weights[2]);
	init_eval[3] = (int) (eval_board_down(map->matrix, map->pc, map->y_len, map->x_len) * weights[3]);
	if((board = (char **)malloc(sizeof(char *) * map->y_len)) == NULL)
		return (-1);
	x = 0;
	while (x < map->y_len)
		board[x++] = (char *)malloc(sizeof(char) * map->x_len);
	if((mv = (t_move *)malloc(sizeof(t_move *))) == NULL)
		return (-1);
	while (tmp != NULL)
	{
		x = 0;
		mv = (t_move *)tmp->content;
		my = mv->y;
		mx = mv->x;
		copy_board(board, map->matrix, map->y_len);
		if (board != NULL)
		{
			place_piece(board, mx, my, map, piece);
			tmp->content_size = (size_t)(
					eval_board_right(board, map->pc, map->y_len) * weights[0]) + init_eval[0];
			tmp->content_size += (size_t)(eval_board_left(board, map->pc, map->y_len) * weights[1]) + init_eval[1];
			tmp->content_size += (size_t)(eval_board_up(board, map->pc, map->y_len, map->x_len) * weights[2]) + init_eval[2];
			tmp->content_size += (size_t)(eval_board_down(board, map->pc, map->y_len, map->x_len) * weights[3]) + init_eval[3];
			tmp = tmp->next;
		}
		else
		{	
			perror("Was unable to copy the board");
			return (-1);
		}
	}
	free(mv);
	return (0);
}
