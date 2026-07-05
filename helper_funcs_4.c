/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 07:11:14 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/05 07:12:08 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_stack(t_input *store, t_dll *lst)
{
	int		i;
	t_node	*nd;

	i = store->num_cnt - 1;
	while (i > -1)
	{
		nd = create_node(store->arr[i]);
		if (!nd)
		{
			lst_clear(lst);
			break ;
		}
		lst_add_front(lst, nd);
		i--;
	}
}
