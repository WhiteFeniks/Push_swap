/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:47 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:43:18 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_comadd(t_c_list **com_list_old, t_c_list *com_list_new)
{
	t_c_list *temp;

	if (!(*com_list_old))
		return ;
	else
	{
		temp = (*com_list_old);
		while ((*com_list_old)->next != NULL)
			(*com_list_old) = (*com_list_old)->next;
		(*com_list_old)->next = com_list_new;
		(*com_list_old) = temp;
	}
}

t_c_list	*ft_comnew(char *com)
{
	t_c_list *com_lst;

	com_lst = (t_c_list *)malloc(sizeof(t_c_list));
	com_lst->com = com;
	com_lst->next = NULL;
	return (com_lst);
}

int			ft_lstlens(t_n_list **stack_a)
{
	t_n_list	*temp;
	int			i;

	i = 0;
	if (!(*stack_a))
		return (-1);
	temp = *stack_a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_n_list	*ft_lstnews(long long value)
{
	t_n_list *n_list_1;

	n_list_1 = (t_n_list *)malloc(sizeof(t_n_list));
	if (!n_list_1)
		return (NULL);
	n_list_1->value = value;
	n_list_1->order = 0;
	n_list_1->flag = 0;
	n_list_1->sort = 0;
	n_list_1->next = NULL;
	n_list_1->previous = NULL;
	return (n_list_1);
}

void		ft_lstadds(t_n_list **first, t_n_list *second)
{
	t_n_list *temp_1;
	t_n_list *temp_2;

	if (!first)
		return ;
	if (!second)
		return ;
	temp_1 = *first;
	while (temp_1->next)
		temp_1 = temp_1->next;
	temp_2 = temp_1;
	temp_2->next = second;
	temp_2 = temp_2->next;
	temp_2->previous = temp_1;
	temp_2->next = NULL;
}
