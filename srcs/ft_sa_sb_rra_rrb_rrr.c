/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_rra_rrb_rrr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:19 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:44:27 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_sa(t_n_list **stack_a)
{
	t_n_list	*temp_1;
	t_n_list	*temp_2;

	if (ft_lstlens(stack_a) < 2)
		return (NULL);
	temp_1 = *stack_a;
	temp_2 = (*stack_a)->next;
	temp_1->next = temp_2->next;
	*stack_a = temp_2;
	(*stack_a)->next = temp_1;
	temp_1->previous = temp_2;
	temp_2 = temp_2->next;
	temp_2 = temp_2->next;
	(*stack_a)->previous = NULL;
	return ((char *)"sa\n");
}

char	*ft_sb(t_n_list **stack_b)
{
	t_n_list	*temp_1;
	t_n_list	*temp_2;

	if (ft_lstlens(stack_b) < 2)
		return (NULL);
	temp_1 = *stack_b;
	temp_2 = (*stack_b)->next;
	temp_1->next = temp_2->next;
	*stack_b = temp_2;
	(*stack_b)->next = temp_1;
	temp_1->previous = temp_2;
	temp_2 = temp_2->next;
	temp_2 = temp_2->next;
	temp_2->previous = temp_1;
	(*stack_b)->previous = NULL;
	return ((char *)"sb\n");
}

char	*ft_rra(t_n_list **stack_a)
{
	t_n_list	*temp_1;
	t_n_list	*temp_2;
	int			i;
	int			j;

	if (ft_lstlens(stack_a) < 2)
		return (NULL);
	i = 0;
	temp_1 = *stack_a;
	temp_2 = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	j = 0;
	while (i != ++j)
		temp_1 = temp_1->next;
	temp_1->next = NULL;
	(*stack_a)->next = temp_2;
	temp_2->previous = *stack_a;
	(*stack_a)->previous = NULL;
	return ((char *)"rra\n");
}

char	*ft_rrb(t_n_list **stack_b)
{
	t_n_list	*temp_1;
	t_n_list	*temp_2;
	int			i;
	int			j;

	if (ft_lstlens(stack_b) < 2)
		return (NULL);
	i = 0;
	temp_1 = *stack_b;
	temp_2 = *stack_b;
	while ((*stack_b)->next != NULL)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	j = 0;
	while (i != ++j)
		temp_1 = temp_1->next;
	temp_1->next = NULL;
	(*stack_b)->next = temp_2;
	temp_2->previous = *stack_b;
	(*stack_b)->previous = NULL;
	return ((char *)"rrb\n");
}

char	*ft_rrr(t_n_list **stack_a, t_n_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	return ((char *)"rrr\n");
}
