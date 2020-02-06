/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:23:43 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:41:15 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_fill_order(t_n_list **stack_a)
{
	t_n_list	*temp_1;
	t_n_list	*tmp_2;
	int			i;

	i = 1;
	while (i <= ft_lstlens(stack_a))
	{
		tmp_2 = NULL;
		temp_1 = *stack_a;
		while (temp_1->order)
			temp_1 = temp_1->next;
		tmp_2 = temp_1;
		temp_1 = *stack_a;
		while (temp_1)
		{
			if (temp_1->order == 0 && (temp_1->value < tmp_2->value))
				tmp_2 = temp_1;
			temp_1 = temp_1->next;
		}
		tmp_2->order = i++;
	}
	return (i - 1);
}
