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

# include <stdlib.h>
# include <unistd.h>

typedef struct s_user_input
{
	int				selected_mode;
	int				bench_mode;
	int				arr[600];
	int				num_cnt;
	double			disordedness;
	int				algo_used;
	int				ops[11];
}					t_input;

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_dl_list
{
	int				len;
	t_node			*head;
	t_node			*tail;
}					t_dll;

int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					has_duplicates(int *arr, int cnt);
double				compute_disorder(int *arr, int cnt);
void				set_ranks(t_input *store);
int					ft_putstr(char *str);
int					ft_strlen(char *str);
int					lst_add_front(t_dll *lst, t_node *new_node);
t_node				*lst_pop_front(t_dll *lst);
void				lst_rotate(t_dll *lst, int dxn);
t_node				*create_node(int val);
void				lst_clear(t_dll *lst);
void				px(t_dll *from, t_dll *to);
void				rx(t_dll *stk);
void				rrx(t_dll *stk);
void				sx(t_dll *stk);
void				populate_stack(t_input *store, t_dll *lst);
#endif
