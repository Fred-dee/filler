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
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int			y_len;
	int			x_len;
	int			player_no;
	char		pc;
	char		oc;
	char		**matrix;
}				t_map;

typedef struct	s_piece
{
	int			y_len;
	int			x_len;
	int			y_trim;
	int			x_trim;
	char		**shape;
}				t_piece;

typedef	struct	s_move
{
	int			x;
	int			y;
}				t_move;

int				get_map(t_map *map, const int fd);
int				init_map(t_map *map, const int fd);
void			free_arr(char **arr, int len);
int				get_piece(t_piece *p, const int fd);
t_list			*gen_moves(t_map *map, t_piece *piece);
int				apply_heuristic(t_list **lst, t_map *map, t_piece *piece);
size_t			eval_board_right(char **b, char pc, int y_len);
size_t			eval_board_left(char **b, char pc, int y_len);
size_t			eval_board_up(char **b, char pc, int y_len, int x_len);
size_t			eval_board_down(char **b, char pc, int y_len, int x_len);
int				index_of(const char *s, const char c);
int				last_index_of(char const *s, char c);
double			sum_dblarr(double *arr, size_t size);
size_t			calc_eval(char **board, t_map *map,
				double *weights, double *init_eval);
#endif
