/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgettail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:14:57 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/13 11:14:58 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgettail(t_list *root)
{
	t_list *tmp;

	tmp = NULL;
	if (root != NULL)
		while (tmp != NULL && tmp->next != NULL)
			tmp =  tmp->next;
	return (tmp);
}
