/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:23:34 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:41:07 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	file_need(t_ps **new_ps, t_n_list **stack_a, t_n_list **stack_b)
{
	if ((*new_ps)->f == 1)
		f_gnl_begin(stack_a, stack_b);
	else if ((*new_ps)->f == 0)
		gnl_begin(stack_a, stack_b);
}

int		main(int argc, char **argv)
{
	t_n_list	*stack_a;
	t_n_list	*stack_b;
	t_c_list	*com_stack;
	t_ps		*new_ps;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	new_ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ft_parse(argv, argc, &stack_a, &new_ps))
	{
		ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack);
		return (write(1, "Error\n", 6));
	}
	ft_init_ps(&stack_a, &new_ps);
	file_need(&new_ps, &stack_a, &stack_b);
	if (!ft_check_sort(&stack_a, &new_ps))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack);
	return (0);
}
