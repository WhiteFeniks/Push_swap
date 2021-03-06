/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:32:29 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:32:31 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i++] - 48;
		if (nbr > 9223372036854775807 && (sign == 1))
			return (-1);
		if (nbr + 1 > 9223372036854775807 && (sign == -1))
			return (0);
	}
	return (nbr * sign);
}
