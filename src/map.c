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
#include <stdio.h>

int		get_player_no(const char *s, t_map *map, const int fd)
{
	int		read_ret;
	char	*str;
	char	*tmp;

	tmp = NULL;
	while ((read_ret = get_next_line(fd, &str)) > 0 && tmp == NULL)
	{
		tmp = ft_strnstr(str, s, ft_strlen(str));
		if (tmp != NULL)
		{
			if ((tmp = ft_strnstr(str, "p1", ft_strlen(str))) != NULL)
			{
				map->player_no = 1;
				map->pc = 'o';
				map->oc = 'x';
			}
			else
			{
				map->player_no = 2;
				map->pc = 'x';
				map->oc = 'o';
			}
			break;
		}
	}
	if (read_ret == -1 || tmp == NULL)
		return (-1);
	return (0);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y_len)
		free(map->matrix[i++]);
	free(map->matrix);
	map->matrix = NULL;
}

int		get_map(t_map *map, const int fd)
{
	int 	read_ret;
	char	*str;
	int		i;
	char	*tmp;

	if((read_ret = get_next_line(fd, &str)) < 0)
		return (-1);
	i = 0;
	if ((tmp = ft_strnstr(str, "Plateau", ft_strlen(str))) != NULL)
		read_ret = get_next_line(fd, &str);
	while (read_ret > 0 && i < map->y_len)
	{
		if((read_ret = get_next_line(fd, &str)) == -1)
			return (-1);
		tmp = ft_strchr(str, ' ');
		tmp = tmp + 1;
		ft_strcpy(map->matrix[i++], tmp);
	}
	return (0);
}

int		init_map(t_map *map,const int fd)
{
	int		read_ret;
	char	*str;
	char	**split;
	int		i;
	char	*tmp;

	if ((get_player_no("mdilapi.filler", map, fd)) == -1)
		return (-1);
	while((read_ret = get_next_line(fd, &str)) > 0)
	{
		tmp = ft_strnstr(str, "Plateau", ft_strlen(str));
		if (tmp != NULL)
			break;
	}
	split = ft_strsplit(str, ' ');
	map->y_len = ft_atoi(split[1]);
	map->x_len = ft_atoi(split[2]);
	if((map->matrix = (char **)malloc(sizeof(char *) * map->y_len)))
	{
		i = 0;
		while(i < map->y_len)
			map->matrix[i++] = ft_strnew(map->x_len);
	}
	// free the split array
	else
		return (-1);
	return (0);
}
