/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 01:05:17 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/04 01:05:19 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_user_input(t_input *store, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (ft_strcmp("simple", av[i] + 2) == 0)
				store->selected_mode = 1;
			else if (ft_strcmp("medium", av[i] + 2) == 0)
				store->selected_mode = 2;
			else if (ft_strcmp("complex", av[i] + 2) == 0)
				store->selected_mode = 3;
			else if (ft_strcmp("bench", av[i] + 2) == 0)
				store->bench_mode = 1;
		}
		else
		{
			store->arr[store->num_cnt++] = ft_atoi(av[i]);
			if (ft_strcmp(av[i], ft_itoa(store->arr[store->num_cnt - 1])))
				return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_input	user_input;

	init_app_input(&user_input);
	if (!process_user_input(&user_input, ac, av)
		|| has_duplicates(user_input.arr, user_input.num_cnt))
	{
        printf("Error\n");
        return (1);
    }
    set_ranks(&user_input);
	return (0);
}
