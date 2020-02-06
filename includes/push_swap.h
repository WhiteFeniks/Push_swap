/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:32:49 by umoff             #+#    #+#             */
/*   Updated: 2020/02/04 19:44:22 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct			s_num_list
{
	long long			value;
	int					order;
	int					sort;
	int					flag;
	struct s_num_list	*previous;
	struct s_num_list	*next;
}						t_n_list;

typedef struct			s_com_list
{
	char				*com;
	struct s_com_list	*next;
}						t_c_list;

typedef	struct
{
	int					next;
	int					max;
	int					flag;
	int					i;
	int					a_b;
	int					v;
	int					f;
	int					j;
}						t_ps;

char					*ft_pa(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_pb(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_ra(t_n_list **stack_a);
char					*ft_rb(t_n_list **stack_b);
char					*ft_rr(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_rra(t_n_list **stack_a);
char					*ft_rrb(t_n_list **stack_b);
char					*ft_rrr(t_n_list **stack_a, t_n_list **stack_b);
char					*ft_sa(t_n_list **stack_a);
char					*ft_sb(t_n_list **stack_b);
t_c_list				*ft_comnew(char *com);
t_n_list				*ft_lstnews(long long value);
int						ft_lstlens(t_n_list **lst);
void					ft_lstadds(t_n_list **first, t_n_list *second);
void					ft_comadd(t_c_list **com_list_old,
						t_c_list *com_list_new);
void					ft_for_three(t_n_list **stack_b,
						t_c_list **com_stack);
int						ft_fill_order(t_n_list **stack_a);
int						ft_calc_max(t_n_list **stack);
int						ft_check_sort(t_n_list **stack_a, t_ps **new_ps);
int						ft_parse(char **argv, int argc, t_n_list **stack_a,
						t_ps **new_ps);
int						ft_free_temp(char **temp, int i);
void					ft_start_sort_a(t_n_list **stack_a,
						t_n_list **stack_b, t_ps **new_ps,
						t_c_list **com_stack);
void					ft_start_sort_b(t_n_list **stack_a,
						t_n_list **stack_b, t_ps **new_ps,
						t_c_list **com_stack);
void					ft_print_com(t_c_list **com_stack);
int						ft_free_all(t_n_list **stack_a, t_n_list **stack_b,
						t_ps **new_ps, t_c_list **com_stack);
void					ft_for_five(t_n_list **stack_a, t_n_list **stack_b,
						t_c_list **com_stack);
void					ft_init_ps(t_n_list **stack_a, t_ps **new_ps);
void					ft_push_next(t_n_list **stack_a, t_n_list **stack_b,
						t_ps **new_ps, t_c_list **com_stack);
int						check_wd(char *word);
void					f_gnl_begin(t_n_list **stack_a, t_n_list **stack_b);
void					f_gnl_end(t_n_list **stack_a, t_n_list **stack_b,
						char **line);
void					gnl_begin(t_n_list **stack_a, t_n_list **stack_b);
void					gnl_end(t_n_list **stack_a, t_n_list **stack_b,
						char **line);
void					file_need(t_ps **new_ps, t_n_list **stack_a,
						t_n_list **stack_b);

#endif
