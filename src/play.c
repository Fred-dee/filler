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

static int		is_valid_move(t_map *map, t_piece *piece, int x, int y)
{
	char	c;
	int		match_count;
	int		i;
	int		j;

	c = map->pc;
	match_count = 0;
	if (piece->y_len - piece->y_trim + y > map->y_len)
		return (-1);
	if (piece->x_len - piece->x_trim + x > map->y_len)
		return (-1);
	i = 0;
	//printf("passed the first tests\n");
	while (i < piece->y_len - piece->y_trim)
	{
		j = 0;
		while (j < piece->x_len - piece->x_trim)
		{
			if(ft_tolower(map->matrix[i + y][j + x]) == c)
			{
				printf("found one of my own pieces %d %d\n",i + y, j + x);
				printf("my shape at %d %d is: %c\n", i + piece->y_trim, j + piece->x_trim, piece->shape[i + piece->y_trim][j + piece->x_trim]);
			}
			if (ft_tolower(map->matrix[i + y][j + x]) == c && piece->shape[i + piece->y_trim][j + piece->x_trim] == '*')
			{
				printf("Foudnd a match\n");
				match_count++;
			}
			else if(ft_tolower(map->matrix[i + y][j + x]) == map->oc && piece->shape[i + piece->y_trim][j + piece->x_trim] == '*')
				return (-1); // this is the case where it'd overlap
			j++;
		}
		//printf("\n");
		i++;
	}
	if (match_count != 1)
		return (-1);
	return (0);
}


t_list		*gen_moves(t_map *map, t_piece *piece)
{
	t_list *head;
	t_move *val_mov;
	int		i;
	int		j;

	i = piece->y_len - piece->y_trim - 1;
	head = NULL;
	//printf("piece->y_len - 1: %d\n", i);
	while (i < map->y_len)
	{
		j = 0;
		while (j + piece->x_len - piece->x_trim - 1 < map->x_len)
		{
			//printf("j + piece->x_len - piece->x_trim - 1: %d\n", j + piece->x_len - piece->x_trim -1);
			if (is_valid_move(map, piece, j, i) == 0)
			{
				//printf("found a valid move \n");
				val_mov = new_move(j, i);
				if (head == NULL)
					head = ft_lstnew(val_mov, sizeof(t_move *));
				else
					ft_lstaddback(&head, ft_lstnew(val_mov, sizeof(val_mov)));
				free (val_mov);
			}
			j++;
		}
		i++;
	}
	return (head);
}
