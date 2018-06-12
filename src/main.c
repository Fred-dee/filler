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
	t_map *map;
	int i;

	i = 0;
	if((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	init_map(map);
	get_map(map);
	while ( i == 0)
	{
		ft_putnbr(map->player_no);
		ft_putchar(' ');
		ft_putnbr(map->x_len);
		ft_putchar('\n');
	}
	free_map(map);
	return (0);
}