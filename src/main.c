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
	int		i;

	i = 0;
	if((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	init_map(map);
	get_map(map);
	get_piece(piece);
	while ( i == 0)
	{
		ft_putnbr(piece->y_len);
		ft_putchar(' ');
		ft_putnbr(piece->x_len);
		ft_putchar('\n');
	}
	free_map(map);
	return (0);
}
