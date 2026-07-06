/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 04:55:56 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/04 04:57:33 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	px(t_dll *from, t_dll *to)
{
	t_node	*nd;

	nd = lst_pop_front(from);
	if (!nd)
		return (0);
	lst_add_front(to, nd);
	return (1);
}

int	rx(t_dll *stk)
{
	lst_rotate(stk, 1);
	return (1);
}

int	rrx(t_dll *stk)
{
	lst_rotate(stk, -1);
	return (1);
}

int	sx(t_dll *stk)
{
	int	tmp;

	if (stk->len < 2)
		return (1);
	tmp = stk->head->val;
	stk->head->val = stk->head->next->val;
	stk->head->next->val = tmp;
	return (1);
}
