/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:23:24 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:40:58 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_sort(t_n_list **stack_a, t_ps **new_ps)
{
	int			i;
	t_n_list	*stack_temp;

	i = 0;
	if (!(*stack_a))
		return (1);
	stack_temp = (*stack_a);
	while (++i == stack_temp->order && (*new_ps)->max != i)
		stack_temp = stack_temp->next;
	return (i == (*new_ps)->max ? 0 : 1);
}
