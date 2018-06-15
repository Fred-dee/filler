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

t_move	*new_move(int x, int y)
{
	t_move *ret;

	ret = NULL;
	if ((ret = (t_move *)malloc(sizeof(t_move))) != NULL)
	{
		ret->x = x;
		ret->y = y;
	}
	return (ret);
}

int		is_valid_move(t_map *map, t_piece *piece, int x, int y)
{
	char	c;
	int		match_count;
	int		i;
	int		j;

	c = map->pc;
	match_count = 0;
	if (piece->y_len + y > map->y_len)
		return (-1);
	if (piece->x_len + x > map->y_len)
		return (-1);
	i = y;
	j = x;
	while (i < )

	return (0);
}
/*
appl_heuristic takes the list of generated moves
assigns the content_size the value of the heuristic
*/
void	apply_heuristic(t_list *lst, t_map *map, t_piece *piece)
{
	(void) lst;
	(void) map;
	(void) piece;
}

t_list	*gen_moves(t_map *map, t_piece *piece)
{
	t_list *head;
	t_move *val_mov;
	int		i;
	int		j;

	i = piece->y_len - 1;
	head = NULL;
	while (i + piece->y_len -1 < map->y_len)
	{
		j = 0;
		while (j + piece->x_len -1 < map->x_len)
		{
			if (is_valid_move(map, piece, j, i) == 0)
			{
				val_mov = new_move(j, i);
				if (head == NULL)
					head = ft_lstnew(val_mov, sizeof(val_mov));
				else
					ft_lstaddback(&head, ft_lstnew(val_mov, sizeof(val_mov)));
			}
			j++;
		}
		i++;
	}
	return (head);
}
