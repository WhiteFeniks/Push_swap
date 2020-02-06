/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:33:05 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:33:08 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intstr(int size)
{
	int	*str;
	int i;

	i = -1;
	if (!size)
		return (0);
	str = malloc(sizeof(int) * size);
	if (!str)
		return (NULL);
	while (++i < size)
		str[i] = 0;
	return (str);
}
