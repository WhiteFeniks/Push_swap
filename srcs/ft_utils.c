/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:29:03 by umoff             #+#    #+#             */
/*   Updated: 2020/02/06 11:45:07 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_wd(char *word)
{
	int i;

	i = 0;
	while (word[i] != '\0')
		if (word[i] == '-' && i == 0 && ft_strlen(word) > 1)
			i++;
		else if (!ft_isdigit(word[i++]))
			return (1);
	return (0);
}
