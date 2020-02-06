/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_math_squad.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:30:54 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:31:11 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ret(int *rez, int acc)
{
	rez[acc - 1] = 1;
	return (rez);
}

int	*ft_long_math_squad(int squad, int acc)
{
	int i;
	int *rez;

	rez = ft_intstr(acc);
	if (squad == 0)
		return (ret(rez, acc));
	rez[acc - 1] = 2;
	while (squad > 1)
	{
		i = acc - 1;
		while (i >= 0)
		{
			rez[i] *= 2;
			while (rez[i] >= 10)
			{
				rez[i - 1] = 2 * rez[i - 1] + (rez[i] / 10);
				rez[i] %= 10;
				i--;
			}
			i--;
		}
		squad--;
	}
	return (rez);
}
