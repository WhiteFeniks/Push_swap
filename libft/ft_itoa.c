/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:31:29 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:31:31 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoamal(long n, unsigned long size)
{
	char *a;

	a = (char *)malloc(sizeof(char) * (size + 1));
	if (!a)
		return (NULL);
	a[size] = '\0';
	while (n)
	{
		a[--size] = '0' + n % 10;
		n /= 10;
	}
	a[--size] = '-';
	return (a);
}

static char		*ft_min_itoa(long n)
{
	size_t	i;
	long	numb;

	i = 0;
	n *= -1;
	i++;
	numb = n;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (ft_itoamal(numb, i));
}

char			*ft_itoa(int n)
{
	size_t	i;
	int		numb;
	char	*a;

	if (n < 0)
		return (ft_min_itoa(n));
	if (n == 0)
	{
		a = (char *)malloc(sizeof(char) * (2));
		if (!a)
			return (NULL);
		a[1] = '\0';
		a[0] = '0';
		return (a);
	}
	i = 0;
	numb = n;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (ft_itoamal(numb, i));
}
