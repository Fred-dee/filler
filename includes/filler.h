/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:45:23 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/11 09:46:03 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int			y_len;
	int 		x_len;
	int			player_no;
	char		pc;
	char		**matrix;
}				t_map;

typedef struct s_piece
{
	int			y_len;
	int			x_len;
	char		**shape;
}				t_piece;

typedef	struct	s_move
{
	int			x;
	int			y;
}				t_move;

int				get_map(t_map *map);
int				init_map(t_map *map);
void			free_map(t_map *map);
int				get_piece(t_piece *p);
t_list			*gen_moves(t_map *map, t_piece *piece);
void			apply_heuristic(t_list *lst, t_map *map, t_piece *piece);
#endif
