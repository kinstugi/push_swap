/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 03:58:00 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/04 03:58:22 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(int *arr, int cnt, int tg)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (arr[i] == tg)
			return (i);
		i++;
	}
	return (-1);
}

static void	sort_tab(int *arr, int cnt)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < cnt)
	{
		j = i + 1;
		while (j < cnt)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	has_duplicates(int *arr, int cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < cnt)
	{
		j = i + 1;
		while (j < cnt)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_ranks(t_input *store)
{
	int	tmp_arr[600];
	int	tmp_arr_2[600];
	int	i;

	i = -1;
	while (++i < store->num_cnt)
		tmp_arr[i] = store->arr[i];
	sort_tab(tmp_arr, store->num_cnt);
	i = -1;
	while (++i < store->num_cnt)
		tmp_arr_2[i] = find_pos(tmp_arr, store->num_cnt, store->arr[i]);
	i = -1;
	while (++i < store->num_cnt)
		store->arr[i] = tmp_arr_2[i];
}

int	ft_putstr(const char *str)
{
	int	len;

	len = ft_strlen(str);
	return (write(1, str, len));
}
