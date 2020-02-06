/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:27:16 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:27:18 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		s1_len;
	size_t	i;

	i = 0;
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[i] != '\0' && i < n)
	{
		s1[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	s1[s1_len] = '\0';
	return (s1);
}
