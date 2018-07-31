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

static int	play_move(t_list *moves, t_map *map, t_piece *piece)
{
	t_move	*fin;

	if (apply_heuristic(&moves, map, piece) == -1)
		return (-1);
	ft_lstquicksort(&moves);
	fin = (t_move *)moves->content;
	if (fin != NULL)
	{
		ft_putnbr_fd(fin->y - piece->y_trim, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(fin->x - piece->x_trim, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

static int	initialize(t_map **map, t_piece **piece)
{
	if ((*map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if ((*piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	if (init_map(*map, 0) == -1)
		return (-1);
	return (1);
}

int			main(void)
{
	t_map	*map;
	t_piece	*piece;
	t_list	*moves;
	int		i;

	i = 0;
	if (initialize(&map, &piece) == -1)
		return (-1);
	while (1)
		if (get_map(map, 0) == -1)
			perror("Couldnt get map");
		else if (get_piece(piece, 0) == -1)
			perror("Couldnt get piece");
		else if ((moves = gen_moves(map, piece)) != NULL)
		{
			if (play_move(moves, map, piece) == -1)
				perror("Error trying to play move");
		}
		else
		{
			ft_putstr_fd("0 0\n", 1);
			exit(1);
		}
	return (0);
}
