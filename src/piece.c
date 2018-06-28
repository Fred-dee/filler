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


int			trim_piece(t_piece *piece)
{
	int		y_len;
	int 	x_len;
	int		i;
	int		j;
	char	**new_shape;

	y_len = 1;
	x_len = 1;
	i = 0;
	j = 0;

	while(i < piece->y_len)
		if(ft_strchr(piece->shape[i++], '*') == NULL)
			y_len++;
	if(piece->y_len - y_len == 0)
		return (0);
	if((new_shape = (char **)malloc(sizeof(char *)* (piece->y_len - y_len))) == NULL)
		return (-1);
	i = 0;
	while (i < piece->y_len)
	{
		if(ft_strchr(piece->shape[i], '*') != NULL)
		{
			new_shape[j++] = ft_strdup(piece->shape[i]);
			//ft_strcpy(new_shape[j++], piece->shape[i]);
		}
		free(piece->shape[i]);
		i++;
	}
	free (piece->shape);
	piece->shape = new_shape;
	piece->y_len = piece->y_len - y_len;
	piece->y_trim = y_len;
	return (0);
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
	}
	if ((p->shape = (char **)malloc(sizeof(char *))) == NULL)
		return (-1);
	i = 0;
	while(i < p->y_len && read_ret > 0)
	{
		read_ret = get_next_line(fd, &str);
		p->shape[i] = ft_strnew(p->x_len);
		ft_strcpy(p->shape[i++], str);
	}
	p->x_trim = 0;
	p->y_trim = 0;
	trim_piece(p);
	return (0);
}
