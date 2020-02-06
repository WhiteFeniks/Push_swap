/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_math_substraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:33:11 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:33:13 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_long_math_substraction(int *a, int *b, int acc)
{
	int i;
	int *rez;

	i = acc - 1;
	rez = malloc(sizeof(int) * acc);
	while (i >= 0)
		rez[i--] = 0;
	i = acc - 1;
	while (i >= 0)
	{
		if (a[i] < b[i])
		{
			a[i] += 10;
			a[i - 1] -= 1;
		}
		rez[i] = a[i] - b[i];
		i--;
	}
	return (rez);
}
