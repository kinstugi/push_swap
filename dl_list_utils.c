/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 04:51:20 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/04 04:51:38 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->val = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	lst_add_front(t_dll *lst, t_node *new_node)
{
	if (!lst || !new_node)
		return (0);
	if (lst->len)
	{
		new_node->next = lst->head;
		new_node->prev = lst->tail;
		lst->tail->next = new_node;
		lst->head->prev = new_node;
	}
	else
	{
		lst->tail = new_node;
	}
	lst->head = new_node;
	lst->len++;
	return (lst->len);
}

t_node	*lst_pop_front(t_dll *lst)
{
	t_node	*ret;

	if (!lst->len)
		return (0);
	ret = lst->head;
	if (lst->len == 1)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else
	{
		lst->head = ret->next;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
	ret->next = NULL;
	ret->prev = NULL;
	lst->len--;
	return (ret);
}

void	lst_rotate(t_dll *lst, int dxn)
{
	if (lst->len < 2 || dxn == 0)
		return ;
	if (dxn > 0)
		lst->head = lst->head->next;
	else
		lst->head = lst->head->prev;
	lst->tail = lst->head->prev;
}

void	lst_clear(t_dll *lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (lst->len)
	{
		tmp = lst_pop_front(lst);
		free(tmp);
	}
}
