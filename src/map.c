/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:53:15 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/11 11:53:16 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y_len)
		free(map->matrix[i++]);
	free(map->matrix);
	map->matrix = NULL;
}

int		get_map(t_map *map)
{
	int 	read_ret;
	char	*str;
	int		i;
	char	*tmp;

	read_ret = get_next_line(0, &str);
	if (read_ret < 0)
		return (-1);
	i = 0;
	while (read_ret > 0 && i < map->y_len)
	{
		if((read_ret = get_next_line(0 &str)) == -1)
			return (-1);
		tmp = ft_strchr(str, ' ');
		ft_strcpy(map->matrix[i++], tmp);
	}
	return (0);
}

int		init_map(t_map *map)
{
	int		read_ret;
	char	*str;
	char	**split;
	int		i;

	if((read_ret = get_next_line(0, &str)) == -1)
		return (-1);
	split = ft_strsplit(str, ' ');
	map->y_len = ft_atoi(split[1]);
	map->x_len = ft_atoi(split[2]);
	if((map->matrix = (char **)malloc(sizeof(char *) * map->y_len)))
	{
		i = 0;
		while(i < map->y_len)
			map->matrix[i++] = ft_strnew(map->x_len);
	}
	else
		return (-1);
	return (0);

}
