/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwaku <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 01:05:35 by kwaku             #+#    #+#             */
/*   Updated: 2026/07/04 01:05:37 by kwaku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_user_input
{
	int	selected_mode;
	int	bench_mode;
	int	arr[600];
	int	num_cnt;
}		t_input;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	init_app_input(t_input *store);
int		has_duplicates(int *arr, int cnt);
void	set_ranks(t_input *store);
#endif
