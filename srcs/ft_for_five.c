/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:23:58 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:42:26 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_part_1_1(t_n_list **stack_a, t_n_list **stack_b,
		t_c_list **com_stack)
{
	while (ft_calc_max(stack_a) != (*stack_a)->order)
		if (!*com_stack)
			*com_stack = ft_comnew(ft_rra(stack_a));
		else
			ft_comadd(com_stack, ft_comnew(ft_rra(stack_a)));
	if (!*com_stack)
		*com_stack = ft_comnew(ft_pb(stack_a, stack_b));
	else
		ft_comadd(com_stack, ft_comnew(ft_pb(stack_a, stack_b)));
}

void	ft_part_1(t_n_list **stack_a, t_n_list **stack_b,
		t_c_list **com_stack)
{
	while (ft_lstlens(stack_a) > 3)
	{
		if (ft_calc_max(stack_a) - 1 == (*stack_a)->order && (!*com_stack)
		&& ft_lstlens(stack_a) == 5)
			*com_stack = ft_comnew(ft_pb(stack_a, stack_b));
		else if (ft_calc_max(stack_a) - 1 == (*stack_a)->order
		&& ft_lstlens(stack_a) == 5)
			ft_comadd(com_stack, ft_comnew(ft_pb(stack_a, stack_b)));
		else if (ft_calc_max(stack_a) == (*stack_a)->order && (!*com_stack))
			*com_stack = ft_comnew(ft_pb(stack_a, stack_b));
		else if (ft_calc_max(stack_a) == (*stack_a)->order)
			ft_comadd(com_stack, ft_comnew(ft_pb(stack_a, stack_b)));
		else if (!*com_stack)
			*com_stack = ft_comnew(ft_ra(stack_a));
		else
			ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	}
}

void	ft_part_2(t_n_list **stack_a, t_c_list **com_stack)
{
	t_n_list	*t2;
	t_n_list	*t3;

	if (!*com_stack)
		*com_stack = ft_comnew(NULL);
	t2 = (*stack_a)->next;
	t3 = t2->next;
	if ((*stack_a)->order > t2->order && (*stack_a)->order < t3->order)
		ft_comadd(com_stack, ft_comnew(ft_sa(stack_a)));
	else if ((*stack_a)->order > t2->order && t2->order > t3->order)
	{
		ft_comadd(com_stack, ft_comnew(ft_sa(stack_a)));
		ft_comadd(com_stack, ft_comnew(ft_rra(stack_a)));
	}
	else if ((*stack_a)->order > t3->order && t2->order < t3->order)
		ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	else if ((*stack_a)->order < t2->order && (*stack_a)->order < t3->order)
	{
		ft_comadd(com_stack, ft_comnew(ft_sa(stack_a)));
		ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	}
	else if ((*stack_a)->order < t2->order && (*stack_a)->order > t3->order)
		ft_comadd(com_stack, ft_comnew(ft_rra(stack_a)));
}

void	ft_for_two(t_n_list **stack_a, t_c_list **com_stack)
{
	t_n_list *t1;

	t1 = (*stack_a)->next;
	if ((*stack_a)->order > t1->order)
		*com_stack = ft_comnew(ft_sa(stack_a));
}

void	ft_for_five(t_n_list **stack_a, t_n_list **stack_b,
		t_c_list **com_stack)
{
	t_n_list	*t2;
	t_n_list	*t3;

	if (ft_lstlens(stack_a) == 2)
		return (ft_for_two(stack_a, com_stack));
	ft_part_1(stack_a, stack_b, com_stack);
	t2 = (*stack_a)->next;
	t3 = t2->next;
	if (!((*stack_a)->order < t2->order && t2->order < t3->order))
		ft_part_2(stack_a, com_stack);
	if (*stack_b && ft_lstlens(stack_b) == 2)
	{
		t2 = (*stack_b)->next;
		if (t2->order > (*stack_b)->order)
			ft_comadd(com_stack, ft_comnew(ft_rb(stack_b)));
		ft_comadd(com_stack, ft_comnew(ft_pa(stack_a, stack_b)));
		ft_comadd(com_stack, ft_comnew(ft_pa(stack_a, stack_b)));
		ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
		ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	}
	else if (*stack_b)
	{
		ft_comadd(com_stack, ft_comnew(ft_pa(stack_a, stack_b)));
		ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	}
}
