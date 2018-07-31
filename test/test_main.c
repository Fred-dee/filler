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
	int i = 0;

	ptr = fopen("map01", "r");
	fd = fileno(ptr);
	if((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	if(init_map(map, fd) == -1)
		printf("Couldnt init the map\n");
	if(get_map(map, fd) == -1)
		printf("Couldnt get the map\n");
	if(get_piece(piece, fd) == -1)
		printf("Couldnt get the piece\n");
	i = 0;
	printf("The pc is: %c\n", map->pc);
	while (i < map->y_len)
	{
		printf("%s\n", map->matrix[i]);
		i++;
	}
	i = 0;
	while (i < piece->y_len)
		printf("%s\n", piece->shape[i++]);
	printf("The maps y->len: %d, its x->len: %d\n",map->y_len, map->x_len );
	printf("The piece y->len: %d and its x_len: %d\n",piece->y_len, piece->x_len);
	moves = gen_moves(map, piece);
	if (moves != NULL)
	{
		apply_heuristic(&moves, map, piece);
		ft_lstquicksort(&moves);
		while (moves != NULL)
		{
			fin = (t_move *)moves->content;
			ft_putnbr_fd(fin->y - piece->y_trim, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(fin->x - piece->x_trim, 1);
			ft_putchar_fd('\n', 1);
			moves = moves->next;
		}
	}
	else
	{
		printf("Moves are null\n");
		ft_putstr_fd("0 0\n", 1);
	}

	return (0);

}
