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

/*
** Thinking of possibly creating a text file that stores a weighting of stratgies
** Say for instance I win more games by maximising teritory vs minimising opponent teritory
** then the value of that heauristic will be heavier
*/

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

char	**copy_board(char  **map, int y_len)
{
	char	**ret;
	int		i;

	if((ret = (char **)malloc(sizeof(char) * y_len)) == NULL)
		return (NULL);
	i = 0;
	while (i < y_len)
	{
		ret[i] = ft_strdup(map[i]);
		i++;
	}
	return (ret);
}


void	apply_heuristic(t_list **lst, t_map *map, t_piece *piece)
{
	char	**board;
	t_list	*tmp;
	size_t	init_eval;
	t_move	*mv;
	int		my;
	int		mx;

	tmp = *lst;
	init_eval = (int) (eval_board_right(map->matrix, map->pc, map->y_len) * 0.4);
	init_eval += (int) (eval_board_left(map->matrix, map->pc, map->y_len) * 0.1);
	init_eval += (int) (eval_board_up(map->matrix, map->pc, map->y_len, map->x_len) * 0.3);
	init_eval += (int) (eval_board_down(map->matrix, map->pc, map->y_len, map->x_len) * 0.2);
	board = (char **)malloc(sizeof(char *) * map->y_len);
	mv = (t_move *)malloc(sizeof(t_move *));
	while (tmp != NULL)
	{
		mv = (t_move *)tmp->content;
		my = mv->y;
		mx = mv->x;
		board = copy_board(map->matrix, map->y_len);
		if (board != NULL)
		{
			place_piece(board, mx, my, map, piece);
			tmp->content_size = (size_t)(
					eval_board_right(board, map->pc, map->y_len) * 0.3) + init_eval;
			tmp->content_size += (size_t)(eval_board_left(board, map->pc, map->y_len) * 0.3);
			tmp->content_size += (size_t)(eval_board_up(board, map->pc, map->y_len, map->x_len) * 0.2);
			tmp->content_size += (size_t)(eval_board_down(board, map->pc, map->y_len, map->x_len) * 0.2);
			tmp = tmp->next;
			free(board);
		}
		board = NULL;
	}
	free(mv);
}
