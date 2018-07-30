/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:16:07 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/12 15:16:08 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>


int			trim_piece(t_piece *p)
{
	int		i;
	int		j;
	int		flag;
	char	**new_piece;

	i = 0;
	while(i < p->y_len)
	{
		if (ft_strchr(p->shape[i], '*') != NULL)
			break;
		i++;
	}
	p->y_trim = i;
	new_piece = (char **)malloc(sizeof(char *) * p->y_len - i);
	flag = p->x_len;
	while (i < p->y_len)
	{
		j = 0;
		while (j < p->x_len)
		{
			if(p->shape[i][j] == '*')
			{
				if (j < flag)
					flag = j;
				break;
			}
			j++;
		}
		i++;
	}
	p->x_trim = flag;
	i = 0;
	while(i < p->y_len - p->y_trim)
	{
		new_piece[i] = ft_strdup(p->shape[i + p->y_trim] + flag);
		i++;
	}
	p->shape = new_piece;
	p->y_len -= p->y_trim;
	p->x_len -= p->x_trim; 
	return (1);
} 

int			get_piece(t_piece *p, const int fd)
{
	char	*tmp;
	int		read_ret;
	char	*str;
	int		i;

	while ((read_ret = get_next_line(fd, &str)) > 0)
	{
		tmp = ft_strnstr(str, "Piece", ft_strlen(str));
		if (tmp != NULL)
		{
			tmp = ft_strchr(str, ' ');
			p->y_len = ft_atoi(tmp++);
			tmp = ft_strchr(tmp, ' ');
			p->x_len = ft_atoi(tmp);
			break;
		}
		free(str);
	}
	if ((p->shape = (char **)malloc(sizeof(char *) * p->y_len)) == NULL)
		return (-1);
	i = 0;
	while(i < p->y_len && (read_ret = get_next_line(fd, &str)) > 0)
	{
		p->shape[i] = ft_strnew(p->x_len);
		ft_strcpy(p->shape[i++], str);
		free(str);
	}
	p->x_trim = 0;
	p->y_trim = 0;
	trim_piece(p);
	return (0);
}
