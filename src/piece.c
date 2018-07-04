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

/*
int			trim_piece(t_piece *p)
{
	int		i;
} */

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
	//trim_piece(p);
	return (0);
}
