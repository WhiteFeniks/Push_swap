/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:26:04 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:42:33 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_for_three_2(t_n_list **stack_b, t_c_list **com_stack)
{
	ft_comadd(com_stack, ft_comnew(ft_rrb(stack_b)));
	ft_comadd(com_stack, ft_comnew(ft_sb(stack_b)));
}

void	ft_for_three(t_n_list **stack_b, t_c_list **com_stack)
{
	t_n_list *tmp_2;
	t_n_list *tmp_3;

	tmp_2 = (*stack_b)->next;
	tmp_3 = tmp_2->next;
	if ((*stack_b)->order > tmp_2->order && (*stack_b)->order < tmp_3->order)
		ft_comadd(com_stack, ft_comnew(ft_rrb(stack_b)));
	else if ((*stack_b)->order < tmp_2->order &&
			(*stack_b)->order > tmp_3->order)
		ft_comadd(com_stack, ft_comnew(ft_sb(stack_b)));
	else if ((*stack_b)->order < tmp_2->order && tmp_2->order > tmp_3->order)
	{
		if (tmp_2->order > tmp_3->order)
			ft_comadd(com_stack, ft_comnew(ft_rb(stack_b)));
	}
	else if ((*stack_b)->order < tmp_2->order && (tmp_2->order < tmp_3->order))
	{
		if (tmp_2->order < tmp_3->order)
		{
			ft_comadd(com_stack, ft_comnew(ft_rb(stack_b)));
			ft_comadd(com_stack, ft_comnew(ft_sb(stack_b)));
		}
	}
	else if ((*stack_b)->order > tmp_2->order && (tmp_2->order < tmp_3->order))
		ft_for_three_2(stack_b, com_stack);
}
