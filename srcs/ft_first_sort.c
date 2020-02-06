/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:23:51 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:41:19 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_next(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	(*stack_b)->flag = (*new_ps)->flag;
	ft_comadd(com_stack, ft_comnew(ft_pa(stack_a, stack_b)));
	ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
	(*new_ps)->next++;
}
