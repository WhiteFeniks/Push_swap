/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:52 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:43:00 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_ps(t_n_list **stack_a, t_ps **new_ps)
{
	(*new_ps)->next = 1;
	(*new_ps)->max = ft_fill_order(stack_a);
	(*new_ps)->flag = 1;
	(*new_ps)->i = 0;
	(*new_ps)->a_b = 0;
}

void	f_gnl_begin(t_n_list **stack_a, t_n_list **stack_b)
{
	int		fd;
	char	*line;

	fd = open("results.txt", O_RDONLY, 0);
	if (fd == -1 || fd > FD_MAX)
		write(1, "Error not file\n", 15);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp(line, "pb"))
			ft_pb(stack_a, stack_b);
		else if (!ft_strcmp(line, "pa"))
			ft_pa(stack_a, stack_b);
		else if (!ft_strcmp(line, "sb"))
			ft_sb(stack_b);
		else if (!ft_strcmp(line, "sa"))
			ft_sa(stack_a);
		else if (!ft_strcmp(line, "ra"))
			ft_ra(stack_a);
		else if (!ft_strcmp(line, "rb"))
			ft_rb(stack_b);
		else
			gnl_end(stack_a, stack_b, &line);
		free(line);
	}
}

void	f_gnl_end(t_n_list **stack_a, t_n_list **stack_b, char **line)
{
	if (!ft_strcmp(*line, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(*line, "rrb"))
		ft_rrb(stack_b);
	else if (!ft_strcmp(*line, "rra"))
		ft_rra(stack_a);
	else if (!ft_strcmp(*line, "rrr"))
		ft_rrr(stack_a, stack_b);
	else
		write(1, "Error\n", 6);
}

void	gnl_begin(t_n_list **stack_a, t_n_list **stack_b)
{
	int		fd;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "pb"))
			ft_pb(stack_a, stack_b);
		else if (!ft_strcmp(line, "pa"))
			ft_pa(stack_a, stack_b);
		else if (!ft_strcmp(line, "sb"))
			ft_sb(stack_b);
		else if (!ft_strcmp(line, "sa"))
			ft_sa(stack_a);
		else if (!ft_strcmp(line, "ra"))
			ft_ra(stack_a);
		else if (!ft_strcmp(line, "rb"))
			ft_rb(stack_b);
		else
			gnl_end(stack_a, stack_b, &line);
		free(line);
	}
}

void	gnl_end(t_n_list **stack_a, t_n_list **stack_b, char **line)
{
	if (!ft_strcmp(*line, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(*line, "rrb"))
		ft_rrb(stack_b);
	else if (!ft_strcmp(*line, "rra"))
		ft_rra(stack_a);
	else if (!ft_strcmp(*line, "rrr"))
		ft_rrr(stack_a, stack_b);
	else
		write(1, "Error\n", 6);
}
