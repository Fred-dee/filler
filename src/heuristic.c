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

char	**copy_board(t_map *map)
{
	char	**ret;
	int		i;

	if((ret = (char **)malloc(sizeof(char) * map->y_len)) == NULL)
		return (NULL);
	i = 0;
	while (i < map->y_len)
	{
		if((ret[i] = ft_strnew(map->x_len)) == NULL)
			return (NULL);
		ft_strcpy(ret[i], map->matrix[i]);
		//printf("ret[%d] = %s\n", i, ret[i]);
		i++;
	}
	return (ret);
}

size_t	eval_board(char **b, char pc, int y_len)
{
	char	*tmp;
	int		i;
	int		j;
	size_t	ret;

	i = 0;
	ret = 0;
	//printf("Player character is: %c\n", pc);
	while (i < y_len)
	{
		j = 0;
		tmp = ft_strrchr(b[i], pc);
		if (tmp != NULL)
		{
			while (*tmp == '.' && *tmp != '\0')
			{
				j++;
				tmp = tmp + 1;
				printf("%c\n", *tmp);
			}
		}
		ret += j;
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

	(void) lst;
	(void) map;
	(void) piece;

	tmp = *lst;
	init_eval = eval_board(map->matrix, map->pc, map->y_len);
	while (tmp != NULL)
	{
		mv = (t_move *)tmp->content;
		printf("%d\n",mv->x);
		board = copy_board(map);
		place_piece(board, mv->x, mv->y, map, piece);
		tmp->content_size = eval_board(board, map->pc, map->y_len) + init_eval;
		tmp = tmp->next;
		free(board);
	}
	//printf("Exiting apply_heuristic\n");
}
