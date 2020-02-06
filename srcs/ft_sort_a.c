/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:14 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:44:46 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_maby_last(t_n_list **stack_a, t_ps **new_ps, t_c_list **com_stack,
		int i)
{
	(*stack_a)->flag = (*new_ps)->flag;
	(*stack_a) = (*stack_a)->next;
	if ((*stack_a)->order == 1)
	{
		(*stack_a) = (*stack_a)->previous;
		return (i);
	}
	(*stack_a) = (*stack_a)->previous;
	ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	i++;
	return (i);
}

int		second_half(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	int i;
	int flag;
	int mid;

	i = 0;
	flag = (*stack_a)->flag;
	mid = ((*new_ps)->max - (*new_ps)->next) / 2 + (*new_ps)->next;
	while ((*stack_a)->flag == flag)
		if ((i == 0) && ((*stack_a)->order == (*new_ps)->next))
		{
			ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
			(*new_ps)->next++;
		}
		else if ((*stack_a)->order <= mid)
		{
			(*stack_a)->sort = 1;
			ft_comadd(com_stack, ft_comnew(ft_pb(stack_a, stack_b)));
		}
		else if ((*stack_a)->order >= mid)
			i = ft_maby_last(stack_a, new_ps, com_stack, i);
	return (i);
}

void	scroll(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	while ((*new_ps)->i--)
		if ((*stack_b) && (*stack_b)->order != (*new_ps)->next)
		{
			ft_rra(stack_a);
			ft_rrb(stack_b);
			ft_comadd(com_stack, ft_comnew((char *)"rrr\n"));
		}
		else
		{
			ft_comadd(com_stack, ft_comnew(ft_rra(stack_a)));
		}
	while (*stack_b && (*stack_b)->sort == 1)
	{
		(*stack_b)->sort = 0;
		ft_rb(stack_b);
	}
}

void	ft_push_b(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	(*stack_a)->sort = 0;
	ft_comadd(com_stack, ft_comnew(ft_pb(stack_a, stack_b)));
}

void	ft_start_sort_a(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	int flag;
	int mid;

	(*new_ps)->i = 0;
	flag = (*stack_a)->flag;
	mid = ((*new_ps)->max - (*new_ps)->next) / 2 + (*new_ps)->next;
	if ((*new_ps)->next > (*new_ps)->max / 2)
	{
		(*new_ps)->flag++;
		(*new_ps)->i = second_half(stack_a, stack_b, new_ps, com_stack);
		scroll(stack_a, stack_b, new_ps, com_stack);
		return ;
	}
	while ((*stack_a)->flag == flag)
		if ((*stack_a)->order == (*new_ps)->next)
		{
			ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
			(*new_ps)->next++;
			(*new_ps)->i++;
		}
		else
			ft_push_b(stack_a, stack_b, new_ps, com_stack);
}
