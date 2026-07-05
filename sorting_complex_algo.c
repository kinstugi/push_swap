/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_complex_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 16:57:07 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/05 16:57:19 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_msb_pos(int num)
{
	int	i;

	i = 15;
	while (!(num & (1 << i)))
		i--;
	return (i);
}

void	sorting_radix_sort(t_input *store, t_dll *stk_a, t_dll *stk_b,
		int disp_op)
{
	int	msb;
	int	i;
	int	j;
	(void) disp_op;
	(void) store;

	i = -1;
	msb = get_msb_pos(stk_a->len - 1);
	while (++i <= msb)
	{
		j = stk_a->len;
		while (j--)
		{
			if (!(stk_a->head->val & (1 << i)))
			{
				px(stk_a, stk_b);
				ft_putstr("pb\n");
			}
			else
			{
				rx(stk_a);
				ft_putstr("ra\n");
			}
		}
		while (stk_b->len)
		{
			px(stk_b, stk_a);
			ft_putstr("pa\n");
		}
	}
}
