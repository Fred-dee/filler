/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:44:52 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/12 14:44:54 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_move	*new_move(int x, int y)
{
	t_move *ret;

	ret = NULL;
	if ((ret = (t_move *)malloc(sizeof(t_move) * 1)) != NULL)
	{
		ret->x = x;
		ret->y = y;
	}
	return (ret);
}

static int		check_piece_len(t_piece *piece, t_map *map, int x, int y)
{
	if (piece->y_len + y > map->y_len)
		return (-1);
	if (piece->x_len + x > map->x_len)
		return (-1);
	return (0);
}

static int		is_valid_move(t_map *map, t_piece *p, int x, int y)
{
	int		match_count;
	int		i;
	int		j;
	char	c;

	if (check_piece_len(p, map, x, y) == -1)
		return (-1);
	match_count = 0;
	i = 0;
	while (i < p->y_len)
	{
		j = 0;
		while (j < p->x_len)
		{
			c = ft_tolower(map->matrix[i + y][j + x]);
			if (c == map->pc && p->shape[i][j] == '*')
				match_count++;
			else if (c == map->oc && p->shape[i][j] == '*')
				return (-1);
			j++;
		}
		i++;
	}
	return ((match_count != 1) ? -1 : 0);
}

t_list			*gen_moves(t_map *map, t_piece *piece)
{
	t_list	*head;
	t_move	*val_mov;
	int		i;
	int		j;

	i = 0;
	head = NULL;
	while (i < map->y_len)
	{
		j = 0;
		while (j + piece->x_len - 1 < map->x_len)
		{
			if (is_valid_move(map, piece, j, i) == 0)
			{
				val_mov = new_move(j, i);
				if (head == NULL)
					head = ft_lstnew(val_mov, sizeof(t_move *));
				else
					ft_lstaddback(&head, ft_lstnew(val_mov, sizeof(val_mov)));
			}
			j++;
		}
		i++;
	}
	return (head);
}
