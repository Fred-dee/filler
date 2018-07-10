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

	ptr = fopen("map00", "r");
	fd = fileno(ptr);
	if((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	if(init_map(map, fd) == -1)
		printf("Couldnt init the map\n");
	if(get_map(map, fd) == -1)
		printf("Couldnt get the map\n");
	//while (i < map->y_len)
	//{
	//	printf("%d: %s\n",i, map->matrix[i]);
	//	i++;
	//}
	if(get_piece(piece, fd) == -1)
		printf("Couldnt get the piece\n");
	i = 0;
	while (i < map->y_len)
	{
		printf("%d: %s\n",i, map->matrix[i]);
		i++;
	}
	i = 0;
	while (i < piece->y_len)
		printf("%s\n", piece->shape[i++]);
	moves = gen_moves(map, piece);
	if (moves != NULL)
	{
		apply_heuristic(&moves, map, piece);
		ft_lstquicksort(&moves);
		while (moves != NULL)
		{
			fin = (t_move *)moves->content;
			//printf("piece y_trim: %d, piece x_trim :%d\n",piece->y_trim, piece->x_trim);
			//printf("this is in main. move has y: %d\n", fin->y);
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
