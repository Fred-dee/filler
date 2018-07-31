/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:16:20 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/30 10:16:38 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		last_index_of(char const *s, char c)
{
	int i;
	int	ret;

	i = 0;
	ret = -1;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				ret = i;
			i++;
		}
		if (s[i] == c)
			return (i);
	}
	return (ret);
}

double		sum_dblarr(double *arr, size_t size)
{
	double		ret;
	size_t	count;

	count = 0;
	ret = 0;
	while (count < size)
		ret += arr[count++]; 
	return (ret);
}
