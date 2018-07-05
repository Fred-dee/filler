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

/*
int			trim_piece(t_piece *p)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	while(i < p->y_len)
	{
		if (ft_strchr(p->shape[i], '*') != NULL)
			break;
		i++;
	}
	//printf("the trim_piece value of i is: %d\n", i);
	p->y_trim = i;
	i = 0;
	flag = 0;
	while(i < p->x_len)
	{
		j = 0;
		while (j < p->y_len)
		{
			if(p->shape[j][i] == '*')
				flag = 1;
			j++;
		}
		if (flag == 1)
			break;
		i++;
	}
	p->x_trim = i;
	//printf("x_tring value is: %d\n", p->x_trim);
	return (1);
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
//	trim_piece(p);
	return (0);
}
