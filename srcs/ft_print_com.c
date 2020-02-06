/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:30 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:43:57 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	in_txt(t_c_list *com_stack_first_new)
{
	FILE		*s1;
	t_c_list	*tmp;

	tmp = com_stack_first_new;
	s1 = fopen("results.txt", "w");
	while (tmp)
	{
		if (tmp->com == NULL)
			tmp = tmp->next;
		fprintf(s1, "%s", tmp->com);
		tmp = tmp->next;
	}
}

void	ft_print_com(t_c_list **com_stack)
{
	t_c_list	*com_stack_temp;
	t_c_list	*com_stack_first;

	com_stack_first = (*com_stack);
	while ((*com_stack)->next)
	{
		com_stack_temp = (*com_stack);
		(*com_stack) = (*com_stack)->next;
		if (com_stack_temp->com && (!ft_strcmp(com_stack_temp->com, "ra\n") &&
					!ft_strcmp((*com_stack)->com, "rb\n")))
		{
			com_stack_temp->com = NULL;
			(*com_stack)->com = "rr\n";
		}
	}
	(*com_stack) = com_stack_first;
	in_txt(com_stack_first);
	while (com_stack_first)
		if (com_stack_first->com)
		{
			write(1, com_stack_first->com, ft_strlen(com_stack_first->com));
			com_stack_first = com_stack_first->next;
		}
		else
			com_stack_first = com_stack_first->next;
}
