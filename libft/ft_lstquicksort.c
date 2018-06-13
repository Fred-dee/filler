/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:19:25 by mdilapi           #+#    #+#             */
/*   Updated: 2018/06/13 11:19:26 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*part(t_list *head, t_list *tail, t_list **n_head, t_list **n_tail)
{
	t_list	*pivot;
	t_list	*prev;
	t_list	*curr;
	t_list	*tmp;
	t_list	*in_t;

	pivot = tail;
	prev = NULL;
	curr = head;
	in_t = pivot;
	while (curr != pivot)
	{
		if (curr->content_size > pivot->content_size)
		{
			if ((*n_head) == NULL)
				(*n_head) = curr;
			prev = curr;
			curr = curr->next;
		}
		else
		{
			if (prev)
				prev->next = curr->next;
			tmp = curr->next;
			curr->next = NULL;
			in_t->next = curr;
			in_t = curr;
			curr = tmp;
		}
	}
	if ((*n_head) == NULL)
		(*n_head) = pivot;
	(*n_tail) = in_t;
	return (pivot);
}

t_list	*qsr(t_list *head, t_list *tail)
{
	t_list	*n_head;
	t_list	*n_tail;
	t_list	*pivot;
	t_list	*tmp;

	if (head == NULL || head == tail)
		return (head);
	n_head = NULL;
	n_tail = NULL;
	pivot = part(head, tail, &n_head, &n_tail);
	if (n_head != pivot)
	{
		tmp = n_head;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		n_head = qsr(n_head, tmp);
		tmp = ft_lstgettail(n_head);
		tmp->next = pivot;
	}
	pivot->next = qsr(pivot->next, n_tail);
	return (n_head);
}

void	ft_lstquicksort(t_list **headref)
{
	(*headref) = qsr(*headref, ft_lstgettail(*headref));
}
