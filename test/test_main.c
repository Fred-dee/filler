/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 08:43:29 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/18 08:43:30 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>


int main(void)
{
	FILE *ptr;
	t_map *map;
	t_piece *piece;
	t_list	*moves;
	t_move	*fin;
	int fd;
	char *str;
	int read_ret;
	int i = 0;
	int j = 0;

	ptr = fopen("map00", "r");
	fd = fileno(ptr);
	if((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	init_map(map, fd);
	get_map(map, fd);
	get_piece(piece, fd);
	moves = gen_moves(map, piece);
	while (i < map->y_len)
		printf("%s\n",map->matrix[i++]);
	i = 0;
	while (i < piece->y_len)
		printf("%s\n",piece->shape[i++]);
	if (moves != NULL)
	{
		while (moves != NULL)
		{
			apply_heuristic(moves, map, piece);
			ft_lstquicksort(&moves);
			fin = (t_move *)moves->content;
			ft_putnbr_fd(fin->y, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(fin->x, 1);
			ft_putchar_fd('\n', 1);
			moves = moves->next;
		}
	}
	else
	{
		ft_putstr_fd("0 0\n", 1);
	}

	return (0);

}
