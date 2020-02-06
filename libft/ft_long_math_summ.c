/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_math_summ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:30:45 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:30:48 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_long_math_summ(int *a, int *b, int acc)
{
	int *rez;
	int i;
	int j;

	i = acc - 1;
	j = acc - 1;
	rez = ft_intstr(acc);
	while (i != -1)
	{
		rez[i] += a[j] + b[j];
		while (rez[i] >= 10)
		{
			rez[i - 1] = rez[i] / 10;
			rez[i] = rez[i] % 10;
		}
		i--;
		j--;
	}
	return (rez);
}
