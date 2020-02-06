/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:36 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:43:51 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_dup(t_n_list **stack_a, int nmb)
{
	t_n_list *tmp;

	tmp = (*stack_a);
	while ((*stack_a))
	{
		if (nmb == (*stack_a)->value)
		{
			(*stack_a) = tmp;
			return (0);
		}
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = tmp;
	return (1);
}

void	make_f(t_ps **new_ps)
{
	(*new_ps)->f = 1;
	(*new_ps)->j++;
}

int		not_string(char **argv, int argc, t_n_list **stack_a,
		t_ps **new_ps)
{
	while ((*new_ps)->j++ < argc - 1)
	{
		if (!ft_strcmp("-v", argv[(*new_ps)->j]))
			return ((*new_ps)->v = 1);
		if (!ft_strcmp("-f", argv[(*new_ps)->j]))
			make_f(new_ps);
		if (ft_strlen(argv[(*new_ps)->j]) > 12 || check_wd(argv[(*new_ps)->j]))
			return (0);
		if (ft_atoi(argv[(*new_ps)->j]) < -2147483649)
			return (0);
		if (ft_atoi(argv[(*new_ps)->j]) > 2147483648)
			return (0);
		if (((*new_ps)->j == 1 && (*new_ps)->f == 0) || ((*new_ps)->j == 2
			&& (*new_ps)->f == 1))
			*stack_a = ft_lstnews(ft_atoi(argv[(*new_ps)->j]));
		else
		{
			if (!ft_check_dup(stack_a, ft_atoi(argv[(*new_ps)->j])))
				return (0);
			ft_lstadds(stack_a, ft_lstnews(ft_atoi(argv[(*new_ps)->j])));
		}
	}
	return (1);
}

int		ft_check_str(t_n_list **stack_a, char **temp, int i, char **argv)
{
	if (argv[1][ft_strlen(argv[1]) - 1] == ' ')
		return (0);
	temp = ft_strsplit(argv[1], ' ');
	while (temp[i])
	{
		if (check_wd(temp[i]))
			return (ft_free_temp(temp, i));
		if (ft_strlen(temp[i]) > 12)
			return (ft_free_temp(temp, i));
		if (ft_atoi(temp[i]) < -2147483649)
			return (ft_free_temp(temp, i));
		if (ft_atoi(temp[i]) > 2147483648)
			return (ft_free_temp(temp, i));
		if (i == 0)
			(*stack_a) = ft_lstnews(ft_atoi(&temp[i][0]));
		else
		{
			if (!ft_check_dup(stack_a, ft_atoi(temp[i])))
				return (ft_free_temp(temp, i));
			ft_lstadds(stack_a, ft_lstnews(ft_atoi(&temp[i][0])));
		}
		free(temp[i++]);
	}
	free(temp);
	return (i);
}

int		ft_parse(char **argv, int argc, t_n_list **stack_a, t_ps **new_ps)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = NULL;
	if (argc == 2)
	{
		i = ft_check_str(stack_a, temp, i, argv) - 1;
		if (i < 1)
			return (0);
	}
	else if (argc == 1)
		return (0);
	else
	{
		(*new_ps)->f = 0;
		(*new_ps)->j = 0;
		return (not_string(argv, argc, stack_a, new_ps));
	}
	return (1);
}
