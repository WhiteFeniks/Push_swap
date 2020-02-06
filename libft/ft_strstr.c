/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:27:07 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:27:09 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		while (haystack[i] == needle[j] || needle[j] == '\0')
		{
			if (needle[j] == '\0')
				return ((char *)haystack);
			i++;
			j++;
		}
		j = 0;
		i = 0;
		haystack++;
	}
	return (NULL);
}
