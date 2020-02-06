/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:25 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:44:11 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <float.h>

int		ft_first_sort_a(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	int i;
	int mid;

	i = 0;
	mid = ((*new_ps)->max - (*new_ps)->next) / 2 + (*new_ps)->next;
	(*new_ps)->flag++;
	while (++i <= (*new_ps)->max && (ft_lstlens(stack_b) < mid))
		if ((*stack_a)->order <= mid)
		{
			if (!*com_stack)
				*com_stack = ft_comnew(ft_pb(stack_a, stack_b));
			else
				ft_comadd(com_stack, ft_comnew(ft_pb(stack_a, stack_b)));
		}
		else if ((*new_ps)->next == 1)
		{
			if (!*com_stack)
				*com_stack = ft_comnew(ft_ra(stack_a));
			else
				ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
		}
	return (0);
}

void	ft_start_sort(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	while (ft_check_sort(stack_a, new_ps))
	{
		while ((*stack_b) && (*stack_b)->sort == 1)
		{
			(*stack_b)->sort = 0;
			ft_rb(stack_b);
		}
		if (!*stack_b)
			ft_start_sort_a(stack_a, stack_b, new_ps, com_stack);
		while (*stack_b && (*stack_b)->order == (*new_ps)->next)
			ft_push_next(stack_a, stack_b, new_ps, com_stack);
		ft_start_sort_b(stack_a, stack_b, new_ps, com_stack);
		while ((*stack_a)->order == (*new_ps)->next)
		{
			(*stack_a)->flag = (*new_ps)->flag;
			ft_comadd(com_stack, ft_comnew(ft_ra(stack_a)));
			(*new_ps)->next++;
		}
	}
}

void	ft_main_sort(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	ft_first_sort_a(stack_a, stack_b, new_ps, com_stack);
	ft_start_sort(stack_a, stack_b, new_ps, com_stack);
	ft_print_com(com_stack);
	ft_free_all(stack_a, stack_b, new_ps, com_stack);
}

/*
** Для пяти чисел
*/

int		ft_five(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	ft_for_five(stack_a, stack_b, com_stack);
	ft_print_com(com_stack);
	ft_free_all(stack_a, stack_b, new_ps, com_stack);
	return (0);
}

/*
** Заполнение двусвязаного списка
*/

int		main(int argc, char **argv)
{
	t_n_list	*stack_a;
	t_n_list	*stack_b;
	t_c_list	*com_stack;
	t_ps		*new_ps;

	stack_a = NULL;
	stack_b = NULL;
	new_ps = (t_ps *)malloc(sizeof(t_ps));
	new_ps->v = 0;
	if (!ft_parse(argv, argc, &stack_a, &new_ps))
	{
		ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack);
		if (ft_lstlens(&stack_a) == 1)
			return (0);
		return (write(1, "Error\n", 6));
	}
	ft_init_ps(&stack_a, &new_ps);
	if (!ft_check_sort(&stack_a, &new_ps))
		return (ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack));
	if (ft_lstlens(&stack_a) <= 5)
		return (ft_five(&stack_a, &stack_b, &new_ps, &com_stack));
	ft_main_sort(&stack_a, &stack_b, &new_ps, &com_stack);
	return (0);
}
