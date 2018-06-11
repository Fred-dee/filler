/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:45:23 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/11 09:46:03 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_map
{
	int			y_len;
	int 		x_len;
	char		**matrix;
}				t_map;

int			get_map(t_map *map);
int			init_map(t_map *map);
void		free_map(t_map *map);
#endif
