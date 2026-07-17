/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_manual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 16:55:37 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/05 16:56:11 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_manual_sort_2(t_input *store, t_dll *stk_a, t_dll *stk_b,
		int disp)
{
	(void)stk_b;
	if (stk_a->len != 2)
		return ;
	if (stk_a->head->val > stk_a->head->next->val)
	{
		rec_op(store, "sa\n", disp);
		sx(stk_a);
	}
}

static void	helper(t_input *store, t_marg *args)
{
	if (args->a > args->b && args->c > args->a)
	{
		rec_op(store, "sa\n", args->disp);
	}
	else if (args->a < args->b && args->c < args->a)
	{
		rec_op(store, "rra\n", args->disp);
	}
	else if (args->c > args->b && args->c < args->a)
	{
		rec_op(store, "ra\n", args->disp);
	}
	else if (args->c < args->b && args->b < args->a)
	{
		rec_op(store, "ra\n", args->disp);
		rec_op(store, "sa\n", args->disp);
	}
}

static void	sorting_manual_sort_3(t_input *store, t_dll *stk_a, t_dll *stk_b,
		int disp)
{
	t_marg	args;

	(void)stk_b;
	if (stk_a->len != 3)
		return ;
	args.a = stk_a->head->val;
	args.b = stk_a->head->next->val;
	args.c = stk_a->tail->val;
	args.disp = disp;
	if (args.a < args.c && args.b > args.c)
	{
		rec_op(store, "rra\n", disp);
		rec_op(store, "sa\n", disp);
	}
	else
		helper(store, &args);
}

void	sorting_manual_sort(t_input *store, t_dll *stk_a, t_dll *stk_b,
		int disp_op)
{
	if (stk_a->len == 2)
		sorting_manual_sort_2(store, stk_a, stk_b, disp_op);
	else if (stk_a->len == 3)
		sorting_manual_sort_3(store, stk_a, stk_b, disp_op);
}
