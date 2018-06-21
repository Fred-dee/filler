/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:20:13 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/21 11:20:13 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

size_t	eval_board_right(char **b, char pc, int y_len)
{
	char	*tmp;
	int		i;
	int		j;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < y_len)
	{
		j = 0;
		tmp = ft_strrchr(b[i], pc);
		if (tmp != NULL)
		{
			tmp++;
			while (*tmp == '.' && *tmp != '\0')
			{
				j++;
				tmp++;
			}
		}
		ret += j;
		i++;
	}
	return (ret);
}

size_t	eval_board_left(char **b, char pc, int y_len)
{
	char	*tmp;
	int		i;
	int		j;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < y_len)
	{
		j = 0;
		tmp = ft_strchr(b[i], pc);
		if (tmp != NULL)
		{
			tmp--;
			while (tmp != b[i] && *tmp == '.')
			{
				j++;
				tmp--;
			}
		}
		ret += j;
		i++;
	}
	return(ret);
}
