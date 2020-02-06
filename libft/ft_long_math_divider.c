/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_math_divider.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:31:24 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:31:26 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numb_of_zeroes(int *div)
{
	int i;

	i = 0;
	while (div[i] == 0)
		i++;
	return (i);
}

int	comparasion(int *a, int *b, int acc)
{
	int i;

	i = 0;
	while (a[i] == 0 && b[i] == 0)
		i++;
	while (a[i] == b[i] && i != acc)
		i++;
	if (i == acc)
		return (1);
	return ((a[i] > b[i]) ? 1 : 0);
}

int	*mult_on_ten(int *num, int i, int acc)
{
	while (i <= acc - 1)
	{
		num[i - 1] = num[i];
		num[i++] = 0;
	}
	return (num);
}

int	st(int *num, int acc)
{
	int i;

	i = 0;
	while (i != acc && num[i] == 0)
		i++;
	return (i);
}

int	*ft_long_math_divider(int *num, int *div, int acc, int numb_of_zero)
{
	int i;
	int *rez;
	int *temp;

	rez = ft_intstr(acc);
	numb_of_zero = acc - 2 - numb_of_zeroes(div);
	num[numb_of_zeroes(div) - 1] = 1;
	num[acc - 1] = 0;
	while (++numb_of_zero < acc)
	{
		temp = ft_intstr(acc);
		while (comparasion(num, temp, acc) || --rez[numb_of_zero] == 10)
		{
			rez[numb_of_zero]++;
			temp = ft_long_math_summ(temp, div, acc);
		}
		temp = ft_long_math_substraction(temp, div, acc);
		num = ft_long_math_substraction(num, temp, acc);
		i = st(num, acc);
		if (i == acc)
			return (rez);
		num = mult_on_ten(num, i, acc);
		free(temp);
	}
	return (rez);
}
