/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:05:20 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/11 10:05:22 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>



int		main(void)
{
	t_map	*map;
	t_piece	*piece;
	t_list	*moves;
	t_move	*fin;
	int		i;

	i = 0;
	if((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	init_map(map);

	while ( i == 0)
	{
		get_map(map);
		get_piece(piece);
		moves = gen_moves(map, piece);
		if (moves != NULL)
		{
			apply_heuristic(moves, map, piece);
			ft_lstquicksort(&moves);
			fin = (t_move *)moves->content;
			ft_putnbr_fd(fin->x, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(fin->y, 1);
			ft_putchar_fd('\n', 1);
		}
		else
			ft_putstr_fd("0 0\n", 1);
	}
	free_map(map);
	return (0);
}
