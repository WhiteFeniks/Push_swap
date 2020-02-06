/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:28:37 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:28:39 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *s1, const char *s2)
{
	int s1_len;
	int i;

	i = 0;
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[i] != '\0')
	{
		s1[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	s1[s1_len] = '\0';
	return (s1);
}