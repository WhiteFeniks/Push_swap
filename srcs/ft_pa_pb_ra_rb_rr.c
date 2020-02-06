/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb_ra_rb_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:41 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:43:34 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_pa(t_n_list **stack_a, t_n_list **stack_b)
{
	t_n_list	*temp_1;

	if (!(*stack_b))
		return (NULL);
	if (!*stack_a)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->previous = NULL;
		(*stack_a)->next = NULL;
	}
	else
	{
		temp_1 = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		if (*stack_b)
			(*stack_b)->previous = NULL;
		(*stack_a)->next = temp_1;
		temp_1->previous = *stack_a;
	}
	return ((char *)"pa\n");
}

char	*ft_pb(t_n_list **stack_a, t_n_list **stack_b)
{
	t_n_list	*temp_1;

	if (!(*stack_a))
		return (NULL);
	if (!*stack_b)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->previous = NULL;
		(*stack_b)->next = NULL;
	}
	else
	{
		temp_1 = *stack_b;
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_a)
			(*stack_a)->previous = NULL;
		(*stack_b)->next = temp_1;
		temp_1->previous = *stack_b;
	}
	return ((char *)"pb\n");
}

char	*ft_ra(t_n_list **stack_a)
{
	t_n_list	*temp_1;
	t_n_list	*temp_2;

	if (ft_lstlens(stack_a) < 2)
		return (NULL);
	temp_1 = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	temp_2 = *stack_a;
	while (temp_2->next != NULL)
		temp_2 = temp_2->next;
	temp_2->next = temp_1;
	temp_1->previous = temp_2;
	temp_1->next = NULL;
	return ((char *)"ra\n");
}

char	*ft_rb(t_n_list **stack_b)
{
	t_n_list	*temp_1;
	t_n_list	*temp_2;

	if (ft_lstlens(stack_b) < 2)
		return (NULL);
	temp_1 = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->previous = NULL;
	temp_2 = *stack_b;
	while (temp_2->next != NULL)
		temp_2 = temp_2->next;
	temp_2->next = temp_1;
	temp_1->previous = temp_2;
	temp_1->next = NULL;
	return ((char *)"rb\n");
}

char	*ft_rr(t_n_list **stack_a, t_n_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	return ((char *)"rr\n");
}
