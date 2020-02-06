/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:23:15 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:40:51 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_calc_max(t_n_list **stack)
{
	t_n_list	*temp;
	int			i;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		if (temp->order > i)
			i = temp->order;
		temp = temp->next;
	}
	return (i);
}
