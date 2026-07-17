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

double	compute_disorder(int *arr, int cnt)
{
	int		i;
	int		j;
	int		mistake;
	double	ret;

	mistake = 0;
	ret = 0;
	i = 0;
	if (cnt < 2)
		return (0);
	while (i < cnt)
	{
		j = i + 1;
		while (j < cnt)
		{
			if (arr[i] > arr[j])
				mistake++;
			j++;
		}
		i++;
	}
	ret = ((cnt - 1) * cnt) / 2;
	ret = mistake / (ret);
	return (ret);
}

void	perform_rotations(t_dll *stk, int cnt, int disp, const char *op)
{
	while (cnt--)
	{
		if (ft_strncmp(op, "ra", 2) == 0 || ft_strncmp(op, "rb", 2) == 0)
			rx(stk);
		else if (ft_strncmp(op, "rra", 3) == 0 || ft_strncmp(op, "rra", 3) == 0)
			rrx(stk);
		if (disp)
			ft_putstr(op);
	}
}
